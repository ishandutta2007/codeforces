// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, sg[MAXN], A[MAXN];
vector<pair<int, pll>> Q;
vector<int> x_v;
set<int> st[MAXN];

void Update(int v, int L, int R, int ind) {
	if (L == R) {
		sg[v] = ind;
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(v << 1, L, mid, ind);
	else Update(v << 1 | 1, mid + 1, R, ind);
	sg[v] = (A[sg[v << 1]] > A[sg[v << 1 | 1]]) ? sg[v << 1] : sg[v << 1 | 1];
}

int Search2(int v, int L, int R, int val) {
	if (A[sg[v]] < val) return -1;
	if (L == R) return sg[v];
	
	int mid = (L + R) >> 1;
       	if (A[sg[v << 1]] >= val) return Search2(v << 1, L, mid, val);
	return Search2(v << 1 | 1, mid + 1, R, val);	
}

int Search(int v, int L, int R, int s, int val) {
	if (A[sg[v]] < val) return -1;
	if (L == R) return sg[v];
	
	int mid = (L + R) >> 1;
	if (s > mid) return Search(v << 1 | 1, mid + 1, R, s, val);
	
	int t = Search(v << 1, L, mid, s, val);
	if (t != -1) return t;
	if (A[sg[v << 1 | 1]] < val) return -1;
	return Search2(v << 1 | 1, mid + 1, R, val);
}

int ind(int x) { return lower_bound(all(x_v), x) - x_v.begin() + 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int x, y, c = 0;
		cin >> s >> x >> y;
		if (s == "remove") c = 1;
	       	else if (s == "find") c = 2;
		Q.push_back({c, {x, y}});
		x_v.push_back(x);
	}

	sort(all(x_v));
	x_v.erase(unique(all(x_v)), x_v.end());
	fill(A, A + MAXN, -1);

	n = n + 2;	
	for (auto e : Q) {
		int x = ind(e.Y.X), y = e.Y.Y;
		if (e.X == 0) {
			st[x].insert(y);
			A[x] = *st[x].rbegin();
			Update(1, 1, n, x);
		} else if (e.X == 1) {
			st[x].erase(y);
			A[x] = st[x].empty() ? -1 : *st[x].rbegin();
			Update(1, 1, n, x);
		} else {
			int t_x = Search(1, 1, n, x + 1, y + 1);
			if (t_x == -1) cout << -1 << endl;
			else cout << x_v[t_x - 1] << sep << *st[t_x].lower_bound(y + 1) << endl;
		}
	}
	
	return 0;
}