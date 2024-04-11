#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> node;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll MOD = 998244353;

int F[MAXN], D[MAXN], n, q;
node sg[MAXN << 1];

// 00, 01, 10, 11

inline node merge(node a, node b, int f) {
	node ans = {{0, 0}, {0, 0}};
	f = F[f];
	ans.X.X = (a.X.Y * b.Y.X + a.X.X * b.X.X * f) % MOD;
	ans.X.Y = (a.X.Y * b.Y.Y + a.X.X * b.X.Y * f) % MOD;
	ans.Y.X = (a.Y.Y * b.Y.X + a.Y.X * b.X.X * f) % MOD;
	ans.Y.Y = (a.Y.Y * b.Y.Y + a.Y.X * b.X.Y * f) % MOD;
	return ans;
}

void update(int ind, int d, int l = 1, int r = n, int v = 1) {
	if (l == r) {
		sg[v] = {{0, 1}, {1, F[d]}};
		D[ind] = d;
		return;
	}

	int mid = (l + r) >> 1;
	if (ind <= mid) update(ind, d, l, mid, v << 1);
	else update(ind, d, mid + 1, r, v << 1 | 1);

	sg[v] = merge(sg[v << 1], sg[v << 1 | 1], D[mid] ? D[mid] * 10 + D[mid + 1] : 20);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			F[i + j]++;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		char d;
		cin >> d;
		update(i, d - '0');
	}

	while (q--) {
		int ind, d;
		cin >> ind >> d;
		update(ind, d);
		cout << sg[1].Y.Y << endl;
	}
	return 0;
}