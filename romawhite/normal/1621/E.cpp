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
const int MAX = 100007;
const int MOD = 998244353;

VI B[MAX];

int T[MAX][3];
int ST[MAX][3];

int P[MAX];

bool f(int l, int r) {
	if (l > r)
		return true;
	if (ST[r][0] < l)
		return true;
	return false;
}

bool Comp(const pair<pair<Int, int>, int>& a, const pair<pair<Int, int>, int> & b) {
	return a.first.first * b.first.second < a.first.second * b.first.first;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int m, n;
		cin >> m >> n;
		VI A(m);
		FOR(i,0,m)
			cin >> A[i];
		sort(ALL(A));
		reverse(ALL(A));
		while (SZ(A) > n)
			A.pop_back();
		reverse(ALL(A));
		FOR(i,0,n) {
			B[i].clear();
			FOR(j,0,3) {
				T[i][j] = 0;
				ST[i][j] = -1;
			}
		}
		vector<pair<pair<Int, int>, int> > C;

		FOR(i,0,n) {
			int k;
			cin >> k;
			Int s = 0;
			FOR(j,0,k) {
				int x;
				cin >> x;
				s += x;
				B[i].push_back(x);
			}
			C.push_back(MP(MP(s, k), i));
		}

		sort(ALL(C), Comp);
		FOR(i,0,n) {
			P[C[i].second] = i;
		}
		FOR(i,0,n) {
			if (C[i].first.first <= 1LL * A[i] * C[i].first.second)
				T[i][0] = 1;
		}
		FOR(i,0,n - 1) {
			if (C[i].first.first <= 1LL * A[i + 1] * C[i].first.second)
				T[i][1] = 1;
		}
		FOR(i,0,n - 1) {
			if (C[i + 1].first.first <= 1LL * A[i] * C[i + 1].first.second)
				T[i][2] = 1;
		}

		FOR(i,0,n) {
			FOR(j,0,3) {
				if (i > 0) {
					ST[i][j] = ST[i - 1][j];
				}
				if (T[i][j] == 0)
					ST[i][j] = i;
			}
		}

		string res = "";
		FOR(i,0,n) {
			Int s = 0;
			for(int x: B[i])
				s += x;
			int pos = P[i];
			int k = SZ(B[i]);
			for(int x: B[i]) {
				Int sx = s - x;
				int npos = lower_bound(ALL(C), MP(MP(sx, k - 1), -1), Comp) - C.begin();
				if (npos > pos)
					npos --;
				bool ok = 1;
				if (sx > 1LL * A[npos] * (k - 1))
					ok = false;
				if (!f(0, min(pos, npos) - 1))
					ok = false;
				if (!f(max(pos, npos) + 1, n - 1))
					ok = false;
				if (pos < npos && ST[npos - 1][2] >= pos)
					ok = false;
				if (pos > npos && ST[npos - 1][1] >= pos)
					ok = false;
				if (ok)
					res += '1';
				else
					res += '0';
			}
		}
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}