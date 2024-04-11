#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, m, h, B[MAXN], A[MAXN];
vector<int> vec;
ll sg[MAXN], lz[MAXN];

inline void push(int v) {
	sg[v] += lz[v];
	if ((v << 1 | 1) < MAXN) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
	}

	lz[v] = 0;
}

void update(int ql, int qr, int val, int l = 1, int r = m, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

inline void add(int x, int val) {
	int ind = lower_bound(all(vec), h - x) - vec.begin();
	if (ind > m) return;
	if (ind == 0) ind++;

	update(ind, m, val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		vec.push_back(B[i]);
	}

	vec.push_back(-1);
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(all(vec));

	for (int i = 1; i <= m; i++)
		update(i, i, -i);

	for (int i = 1; i <= m; i++)
		add(A[i], 1);

	int ans = 0;
	if (sg[1] >= 0) ans++;
	
	for (int i = m + 1; i <= n; i++) {
		add(A[i - m], -1);
		add(A[i], 1);
		if (sg[1] >= 0) ans++;
	}

	cout << ans << endl;
	return 0;
}