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
typedef long long ll;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 1000000007; 

vector<pair<int, PII> > G[MAX];

vector<Int> A[2];

int cnt[MAX];
Int total = 0;

void dfs(int v, int p, Int sw) {
	cnt[v] = 0;
	if (SZ(G[v]) == 1 && v != 0) {
		cnt[v] += 1;
		total += sw;
	}
	for(auto x: G[v]) {
		int to = x.first;
		if (to == p) continue;
		dfs(to, v, sw + x.second.first);
		cnt[v] += cnt[to];
		int w = x.second.first;
		while (w > 0) {
			Int nw = w / 2;
			A[x.second.second - 1].push_back(1LL * (w - nw) * cnt[to]);
			w = nw;
		}
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		Int s;
		cin >> n >> s;

		FOR(i,0,n) {
			G[i].clear();
			cnt[i] = 0;
		}
		FOR(i,0,n - 1) {
			int u, w, v, c;
			cin >> u >> w >> v >> c;
			-- u; --w;
			G[u].push_back(MP(w, MP(v, c)));
			G[w].push_back(MP(u, MP(v, c)));
		}
		A[0].clear();
		A[1].clear();
		total = 0;
		dfs(0, -1, 0);
		sort(ALL(A[0]));
		reverse(ALL(A[0]));
		sort(ALL(A[1]));
		reverse(ALL(A[1]));

		if (total <= s) {
			cout << 0 << endl;
			continue;
		}

		Int target = total - s;

		int res = INF;

		Int sb = 0;
		int ptrb = 0;
		while (ptrb < SZ(A[1]) && sb < target) {
			sb += A[1][ptrb];
			ptrb ++;
		}
		if (sb >= target) {
			res = min(res, 2 * ptrb);
		}

		FOR(i,0,SZ(A[0])) {
			sb += A[0][i];
			while (ptrb > 0 && sb - A[1][ptrb - 1] >= target) {
				sb -= A[1][ptrb - 1];
				ptrb -= 1;
			}
			if (sb >= target)
				res = min(res, i + 1 + ptrb * 2);
		}

		cout << res << endl;

	}
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}