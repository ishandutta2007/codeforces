#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int dp[100002][32];
ll ha[2000000][4];
ll power[2000000][4];
int MX = 1e6;
struct Hash {
    ll SEED;
    ll MOD;
    int len=0;
    int num;
    Hash(ll seed,ll mod,int NUM) {
        len=0;
        num=NUM;
        SEED = seed, MOD=mod;
        power[0][num]=1;
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
};
ll b1 = 1337, m1 = 1000000007;
ll b2 = 1007, m2 = 1000000009;
Hash H1(b1,m1,0);
Hash H2(b2,m2,1);
Hash H3(b1,m1,2);
Hash H4(b2,m2,3);
int n,m;
int getLongest(int i,int j) {
    int l = 1,r = n;
    int ret=0;
    while(l<=r){
        int mid = (l+r)/2;
        if (i+mid-1>=n || j+mid-1>=m) r=mid-1;
        else if (H1.get(i,i+mid-1)==H3.get(j,j+mid-1) && H2.get(i,i+mid-1)==H4.get(j,j+mid-1)) ret=mid, l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x;
    cin>>n>>s>>m>>t>>x;
    for (int i=0;i<n;i++) {
        for (int j=0;j<=x;j++) {
            dp[i][j]=-1;
        }
    }
    for (int i=0;i<n;i++) {
        H1.Add(s[i]);
        H2.Add(s[i]);
    }
    for (int i=0;i<m;i++) {
        H3.Add(t[i]);
        H4.Add(t[i]);
    }
    dp[0][0]=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<=x;j++) {
            int cur = dp[i][j];
            int L = getLongest(i,cur);
            if (cur<0)continue;
            if (cur==m){
                cout<<"YES"<<endl;
                return 0;
            }
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if (t[cur]==s[i]) {
                dp[i+L][j+1] = max(dp[i+L][j+1],cur+L);
            }
        }
    }
    for (int i=0;i<=x;i++){
        if (dp[n][i]>=m){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}