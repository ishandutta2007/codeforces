#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
int n, m;
LL a[SZ], dp[SZ];

LL solve() {
    a[n]=0;
    dp[n]=dp[n+1]=dp[n+2]=dp[n+4]=0;
    for (int i = n-1; i >= 0; i--) {
        dp[i]=a[i]+0+dp[i+2];
        dp[i]=min(dp[i],a[i]+0+0+dp[i+3]);
        dp[i]=min(dp[i],a[i]+a[i+1]+0+dp[i+3]);
        dp[i]=min(dp[i],a[i]+a[i+1]+0+0+dp[i+4]);
    }
    return dp[0];
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        
        LL r = solve();
        cout<<r<<"\n";
    }
    
    return 0;
}