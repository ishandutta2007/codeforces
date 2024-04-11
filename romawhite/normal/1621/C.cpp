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
const int MAX = 200007;
const int MOD = 998244353;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		VI R(n, -1);
		int last = -1;
		FOR(i,0,n) {
			if (R[i] != -1)
				continue;
			VI C;
			while (true) {
				cout << "? " << i + 1 << endl;
				int v;
				cin >> v;
				-- v;
				C.push_back(v);
				if (SZ(C) > 1 && v == C[0])
					break;
			}
			FOR(j,0,SZ(C) - 1) {
				R[C[j]] = C[j + 1];
			}
		}
		cout << "! ";
		FOR(i,0,n) {
			cout << R[i] + 1 << ' ';
		}
		cout << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}