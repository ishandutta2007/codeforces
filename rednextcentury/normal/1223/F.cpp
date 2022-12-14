#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MX = 1000005;
ll ha[2000000][2];
ll power[2000000][2];
struct Hash {
    ll SEED;
    ll MOD;
    int len=0;
    int num;
    Hash(ll seed,ll mod,int NUM) {
        len=0;
        num=NUM;
        SEED = seed, MOD=mod;
 
    }
    void Add(int x)
    {
        if (len==0)
            ha[0][num]=x;
        else
            ha[len][num] = (ha[len-1][num] * SEED + x)%MOD;
        len++;
    }
    void Rem() {
        len--;
    }
    int getFull() {
        if (len==0)return 0;
        return ha[len-1][num];
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
};
long long mod1=1000000007;
long long mod2=1000000009;
long long seed1=1337;
long long seed2=1007;
int a[1000000];
ll ret=0;
map<pair<int,int> ,int> mp;
void solve(int l,int r) {
    if (l>=r)return;
    int mid = (l+r)/2;
    stack<int> st;
    Hash h1(seed1,mod1,0);
    Hash h2(seed2,mod2,1);
    mp[{0,0}]++;
    for (int i=mid+1;i<=r;i++) {
        if (!st.empty() && st.top()==a[i]){
            st.pop();
            h1.Rem();
            h2.Rem();
        } else {
            st.push(a[i]);
            h1.Add(a[i]);
            h2.Add(a[i]);
        }
        mp[{h1.getFull(),h2.getFull()}]++;
    }
 
    Hash h3(seed1,mod1,0);
    Hash h4(seed2,mod2,1);
    while(!st.empty())st.pop();
    for (int i=mid;i>=l;i--) {
        if (!st.empty() && st.top()==a[i]){
            st.pop();
            h3.Rem();
            h4.Rem();
        } else {
            st.push(a[i]);
            h3.Add(a[i]);
            h4.Add(a[i]);
        }
        ret+=mp[{h3.getFull(),h4.getFull()}];
    }
    mp.clear();
    solve(l,mid-1);
    solve(mid+1,r);
}
int main()
{

    power[0][0]=1;
    for (int i=1;i<=MX;i++)
        power[i][0] = (power[i-1][0] * seed1)%mod1;

    power[0][1]=1;
    for (int i=1;i<=MX;i++)
        power[i][1] = (power[i-1][1] * seed2)%mod2;
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)scanf("%d",&a[i]);
        ret=0;
        solve(1,n);
        printf("%lld\n",ret);
    }
}