#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long a[1000];
long long w[1000];
long long dp[51][51][51];
long long mod = 998244353;
long long P(long long a,long long b) {
    if (b==0)return 1;
    long long x = P(a,b/2);
    x = (x*x)%mod;
    if(b%2)x = (x*a)%mod;
    return x;
}
long long inv(long long x) {
    return P(x,mod-2);
}
int n,m;
int cur=1;
int startHate = 0,startLike=0;
long long solve(int i,int add,int my) {
    if (i==m)return 0;
    if (dp[i][add][my]!=-1)
        return dp[i][add][my];
    dp[i][add][my]=0;
    long long mine = w[cur]+my*a[cur];
    long long sumLike = startLike + add;
    long long sumHate = startHate - (i-add);
    long long total = sumHate+sumLike;
    total = (total+mod)%mod;
    long long in = inv(total);
    if (a[cur]==1)sumLike -= mine;
    else sumHate-=mine;

    sumLike = (sumLike+mod)%mod;
    sumHate = (sumHate+mod)%mod;
    mine = (mine+mod)%mod;
    long long &ret = dp[i][add][my];

    long long p1 = (sumLike*in)%mod;
    long long p2 = (sumHate*in)%mod;
    long long p3 = (mine*in)%mod;
    long long ext = p3;
    if (a[cur]!=1) {
        ext = (((mod-mine)%mod)*in)%mod;
    }

    ret = (solve(i+1,add+1,my)*p1)%mod + (solve(i+1,add,my)*p2)%mod;
    ret%=mod;

    if (a[cur]==1) {
        ret+= ext+(p3*solve(i+1,add+1,my+1)%mod);
    } else {
        ret+= ext+(p3*solve(i+1,add,my+1))%mod;
    }
    ret%=mod;
    return dp[i][add][my]=ret;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==0)a[i]=-1;
    }
    long long sum=0;
    for (int i=1;i<=n;i++) {
        cin >> w[i];
        if (a[i]==1)startLike+=w[i];
        else startHate+=w[i];
    }
    for (int i=1;i<=n;i++) {
        cur = i;
        memset(dp, -1, sizeof(dp));
        cout << (w[cur] + solve(0, 0, 0)) << endl;
    }
}