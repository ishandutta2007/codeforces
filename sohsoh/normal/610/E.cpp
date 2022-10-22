// Sohsoh84 :)))
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
const ll MAXK = 10;

struct mat {
	int n, v[MAXK][MAXK];
	
	mat() {}
	mat(int n) : n(n) {
		for (int i = 0; i < MAXK; i++)
			for (int j = 0; j < MAXK; j++)
				v[i][j] = 0;
	}

	mat operator+ (const mat& b) {
		mat ans = mat(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans.v[i][j] = v[i][j] + b.v[i][j];
		return ans;
	}
};

int n, q, k, lz[MAXN], dist[MAXK][MAXK];
pair<pll, mat> sg[MAXN];
string s;

pair<pll, mat> merge(pair<pll, mat> a, pair<pll, mat> b) {
	a.Y.v[a.X.Y][b.X.X]++;
	a.Y = a.Y + b.Y;
	a.X.Y = b.X.Y;
	return a;
}

inline void push(int v, int len) {
	if (lz[v] >= 0) {
		sg[v] = {{lz[v], lz[v]}, mat(k)};	
		sg[v].Y.v[lz[v]][lz[v]] = len;
		if ((v << 1 | 1) < MAXN) lz[v << 1] = lz[v << 1 | 1] = lz[v];
		lz[v] = -1;
	}
}

void build(int l = 1, int r = n, int v = 1) {
	lz[v] = -1;
	sg[v].Y = mat(k);
	if (l == r) {
		sg[v].X.X = sg[v].X.Y = s[l] - 'a';
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
}

void update(int ql, int qr, int c, int l = 1, int r = n, int v = 1) {
	push(v, r - l);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] = c;
		push(v, r - l);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, c, l, mid, v << 1);
	update(ql, qr, c, mid + 1, r, v << 1 | 1);
	sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> k >> s;
	s = '-' + s;
	build();
	
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			update(l, r, c - 'a');
		} else {
			string s;
			cin >> s;
			ll ans = find(all(s), char(sg[1].X.X + 'a')) - s.begin() + 1;

			for (int i = 0; i < k; i++)
				for (int j = 0; j < k; j++)
					ans += sg[1].Y.v[s[i] - 'a'][s[j] - 'a'] * (j - i > 0 ? j - i : j - i + k);
			cout << (ans += s.size() - 1) / s.size() << endl;
		}
	}
	return 0;
}