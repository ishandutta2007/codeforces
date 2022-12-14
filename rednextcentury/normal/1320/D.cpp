#include<bits/stdc++.h>
using namespace std;
#define ll long long
int L[1000000], R[1000000];
int pre[1000000];
int tree[1000000];
int a[1000000];
int loc[1000000];
ll ha[2000000][2];
ll power[2000000][2];
struct Hash {
    ll SEED;
    ll MOD;
    int len=0;
    int num;
    Hash(){}
    Hash(ll seed,ll mod,int NUM) {
        len=0;
        num=NUM;
        SEED = seed, MOD=mod;
        power[0][num]=1;
        int MX=300000;
        for (int i=1;i<=MX;i++)
            power[i][num] = (power[i-1][num] * SEED)%MOD;

    }
    void Add(char x)
    {
        if (len==0)
            ha[0][num]=x;
        else
            ha[len][num] = (ha[len-1][num] * SEED + x)%MOD;
        len++;
    }
    //i,j inclusive
    ll get(int i, int j) {
        ll ret = ha[j][num];
        if (i) ret -= ha[i-1][num] * power[j - i + 1][num];
        ret = (ret % MOD + MOD) % MOD;
        return ret;
    }
    ll getLast(int x) {
        int l = len - x;
        int r = len - 1;
        return get(l,r);
    }
} hash1,hash2;
void build(string s){
    hash1 = Hash(7013, 1000003211, 0);
    hash2 = Hash(10369, 999992867, 1);
    for (auto x:s) hash1.Add(x), hash2.Add(x);
}
bool IsEqual(int l1,int r1,int l2,int r2){
    if (r1-l1+1 != r2-l2+1)assert(0);
    if (l1>r1)return 1;
    return hash1.get(l1,r1)==hash1.get(l2,r2) && hash2.get(l1,r1)==hash2.get(l2,r2);
}
int CountOnes(int l,int r){
    if (l>r)return 0;
    return pre[r]-pre[l-1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    string s;
    cin>>n>>s>>q;
    s="."+s;
    int num=0;
    string t="";
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]=='1');
        if (s[i]=='0') loc[i] = num++, t+="0";
        if (s[i]=='0')L[i]=i;
        else L[i]=L[i-1];
    }
    pre[n+1]=pre[n];
    R[n+1]=n+1;
    for (int i=n;i>=1;i--){
        if (s[i]=='0')R[i]=i;
        else R[i]=R[i+1];
    }
    int cur=0;
    for (int i=1;i<=n;i++){
        if (s[i]=='0'){
            int val = CountOnes(i, R[i+1]) % 2;
            t[cur]=char('0'+val);
            cur++;
        }
    }
    build(t);
    while(q--){
        int i,j,len;
        cin>>i>>j>>len;
        int l1=i,r1=i+len-1;
        int l2=j,r2=j+len-1;
        if (CountOnes(l1,r1)!=CountOnes(l2,r2)){
            cout<<"No\n";
        } else {
            if (CountOnes(l1,r1)==r1-l1+1){
                cout<<"Yes\n";
            } else {
                l1 = R[l1];
                r1 = L[r1];
                l2 = R[l2];
                r2 = L[r2];
                bool ok = 1;
                if ((CountOnes(i,l1-1)%2) != (CountOnes(j, l2-1)%2)) ok=0;
                if ((CountOnes(r1+1,i+len-1)%2) != (CountOnes(r2+1, j+len-1)%2)) ok=0;
                if (!ok)cout<<"No\n";
                else {
                    if (IsEqual(loc[l1],loc[r1]-1,loc[l2],loc[r2]-1))cout<<"Yes\n";
                    else cout<<"No\n";
                }
            }
        }
    }
}