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
const int MAX = 507;
const int MOD = 998244353;

int A[MAX][MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		FOR(i,0,2 * n)
			FOR(j,0,2 * n)
				cin >> A[i][j];
		Int res = 0;
		FOR(i,n,2*n)
			FOR(j,n,2*n)
				res += A[i][j];
		int mn = INF;
		mn = min(mn, A[0][n]);
		mn = min(mn, A[0][2 * n - 1]);
		mn = min(mn, A[n - 1][n]);
		mn = min(mn, A[n - 1][2 * n - 1]);
		mn = min(mn, A[n][0]);
		mn = min(mn, A[2 * n - 1][0]);
		mn = min(mn, A[n][n - 1]);
		mn = min(mn, A[2 * n - 1][n - 1]);
		res += mn;
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}