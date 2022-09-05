#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;

int dp[5000][5000];

int main() {
    int n,k;
    int t[5000];
    int d[5000];
    cin >> n >> k;
    FOR(i,1,n+1)
        cin >> t[i] >> d[i];
    FOR(i,0,5000)
        FOR(j,0,5000)
            dp[i][j] = INF;
    FOR(i,0,5000)
        dp[i][0] = 1;
    FOR(i,1,n+1)
        FOR(j,1,i+1){
            int b = max(dp[i-1][j-1],t[i]) + d[i];
            dp[i][j] = min(b,dp[i-1][j]);
    }
    /*for(int j=n;j>=0;--j){
        for(int i=0;i<=n;++i)
            cout << dp[i][j] << ' ';
        cout << endl;
    }*/
    int res = 0;
    FOR(i,0,n-k)
        res = max(res,t[i+k+1] - dp[n][i]);
    res = max(res,86401 - dp[n][n-k]);
    cout << res;
    return 0;
}