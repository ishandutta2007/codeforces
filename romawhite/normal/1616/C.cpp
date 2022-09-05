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

		int n;
		cin >> n;

		VI A(n);
		FOR(i,0,n) {
			cin >> A[i];
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		int res = 0;
		FOR(i,0,n)
			FOR(j,i + 1, n) {
				int c = 0;
				FOR(k,0,n)
					if ((A[k] - A[i]) * (k - j) == (A[k] - A[j]) * (k - i))
						++ c;
				res = max(res, c);
			}
		cout << n - res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}