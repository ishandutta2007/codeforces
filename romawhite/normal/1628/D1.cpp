#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 2007;
const int MOD = 1000000007;

Int dp[MAX][MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;

	Int inv2 = (MOD + 1) / 2;
	FOR(tt,0,t) {
		int n, m, k;
		cin >> n >> m >> k;
		FOR(i,0,n + 2)
			FOR(j,0,n + 2) {
				dp[i][j] = -1;
			}
		dp[n][m] = 0;
		RFOR(i,n,0){
			FOR(j,0,i + 1) {
				if (dp[i + 1][j + 1] == -1 && dp[i + 1][j] == -1) {
					continue;
				}
				if (dp[i + 1][j + 1] == -1) {
					dp[i][j] = dp[i + 1][j];
					continue;
				}
				if (dp[i + 1][j] == -1) {
					dp[i][j] = (dp[i + 1][j + 1] + k) % MOD;
					continue;
				}
				dp[i][j] = (dp[i + 1][j] + dp[i + 1][j + 1]) * inv2 % MOD;
			}
		}
		// FOR(i,0,n + 1){
		// 	FOR(j,0,i + 1) {
		// 		cout << dp[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		
		cout << dp[0][0] << endl;
	}
	
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}