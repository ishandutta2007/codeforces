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
const int MAX = 1 << 20;
const int MOD = 1000000007;


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n, m;
		cin >> m >> n;
		vector<VI> A(m, VI(n));
		FOR(i,0,m)
			FOR(j,0,n)
				cin >> A[i][j];
		int L = 0;
		int R = INF + 1;
		while (R - L > 1) {
			int M = (L + R) / 2;
			vector<bool> ok(n, 0);
			bool ok2 = false;
			FOR(i,0,m) {
				int cnt = 0;
				FOR(j,0,n) {
					if (A[i][j] >= M) {
						++ cnt;
						ok[j] = 1;
					}
				}
				if (cnt >= 2)
					ok2 = true;
			}
			FOR(i,0,n)
				ok2 &= ok[i];
			if (ok2) {
				L = M;
			} else {
				R = M;
			}
		}
		cout << L << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}