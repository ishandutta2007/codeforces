#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, char> edge;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 3e6 + 10;
const ll INF = 1e8;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<edge> adj[MAXN];
bool marked[MAXN];
int ans[MAXN], n, k, dp[MAXN], tot = 0, ind[MAXN];

bool cmp(edge x, edge y) {
	if (x == y || x.Y < y.Y || (x.Y == y.Y && x.X < y.X)) return true;
		return false;
}

struct SegmentTree {
	public:
		int *lz = new int[MAXN], *sg = new int[MAXN];
		SegmentTree() {
			fill(sg, sg + MAXN, INF);
			fill(lz, lz + MAXN, 0);
		}
		
		inline void push(int v) {
			if (lz[v]) {
				sg[v] += lz[v];
				if (2 * v + 1 < MAXN) {
					lz[2 * v] += lz[v];
					lz[2 * v + 1] += lz[v];
				}

				lz[v] = 0;
			}
		}

		void Update(int v, int l, int r, int ql, int qr, int val) {
			if (r < l || r < ql || l > qr) return;
			if (qr >= r && ql <= l) {
				lz[v] += val;
				push(v);
				return;
			}

			push(v);
			int mid = (l + r) >> 1;
			Update(2 * v, l, mid, ql, qr, val);
			Update(2 * v + 1, mid + 1, r, ql, qr, val);
			sg[v] =	min(sg[2 * v], sg[2 * v + 1]);
		}

		int Query(int v, int l, int r, int ql, int qr) {
			push(v);
			if (r < l || r < ql || l > qr) return INF + INF;
			if (qr >= r && ql <= l) return sg[v];
			int mid = (l + r) >> 1;
			return min(Query(2 * v, l, mid, ql, qr), Query(2 * v + 1, mid + 1, r, ql, qr));
		}

		void Update(int ql, int qr, int val) { Update(1, 1, n, ql, qr, val); }
		int Query(int ql, int qr) { return Query(1, 1, n, ql, qr); }
		void Reset(int v, int val) {
			int tval = Query(v, v);
			Update(v, v, val - tval);
		}
};

SegmentTree sg1, sg2;


void dfs(int v, int d) {
	sg1.Update(1, n, 1);
	if (marked[v]) {
		tot++;		
		sg2.Update(1, n, 1);	
		int t_ans = min(d, tot);
		t_ans = min(t_ans, sg1.Query(1, n));
		t_ans = min(t_ans, sg2.Query(1, n));
		sg2.Reset(v, t_ans + 1);
		sg1.Reset(v, t_ans);
		ans[v] = t_ans;
	} else {
		int t_ans = d;
		t_ans = min(t_ans, sg1.Query(1, n));
		sg2.Reset(v, t_ans);	
		sg1.Reset(v, t_ans);
	}

	for (auto e : adj[v]) dfs(e.X, d + 1);
	sg1.Reset(v, INF);
	sg2.Reset(v, INF);
	sg1.Update(1, n, -1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int par;
		char c;
		cin >> par >> c;
		adj[par].push_back({i, c});
	}

	for (int i = 0; i <= n; i++) sort(all(adj[i]), cmp);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		marked[x] = true;	
		ind[i] = x;
	}	

	dfs(0, 0);
	for (int i = 0; i < k; i++) cout << ans[ind[i]] << sep;
	cout << endl;
	return 0;
}