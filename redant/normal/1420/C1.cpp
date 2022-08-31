#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
int n, q;
int a[SZ];
LL dp[SZ][2];

LL solve() {
    dp[0][0]=0;
    dp[0][1]=a[0];
    LL r = a[0];
    REP(i, n-1) {
        dp[i+1][0] = max(dp[i][0], dp[i][1]-a[i+1]);
        dp[i+1][0] = max(0ll, dp[i+1][0]);
        dp[i+1][1] = max(dp[i][1], dp[i][0] + a[i+1]);
        r = max(r, dp[i+1][0]);
        r = max(r, dp[i+1][1]);
        // cout<<dp[i+1][0]<<", "<<dp[i+1][1]<<endl;
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>q;
        REP(i, n) {
            cin>>a[i];
        }        
        cout<<solve()<<"\n";
    }
    
    return 0;
}