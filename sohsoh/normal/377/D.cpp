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

const ll MAXN = 2e6 + 10;
const ll N = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, lz[MAXN];
pair<pll, int> A[MAXN];
vector<pll> L[MAXN];
vector<int> V[MAXN];
pll sg[MAXN];

inline void Push(int v) {
	sg[v].X += lz[v];
	if ((v << 1 | 1) < MAXN) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
	}

	lz[v] = 0;
}

void Build(int v, int L, int R) {
	if (L == R) sg[v] = {0, L};
	else {
		int mid = (L + R) >> 1;
		Build(v << 1, L, mid);
		Build(v << 1 | 1, mid + 1, R);
		sg[v] = {0, L};
	}
}

void Update(int v, int L, int R, int QL, int QR, int val) {
	Push(v);
	if (QR < QL) return;
	if (QL == L && QR == R) {
		lz[v] += val;
		Push(v);
		return;
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, QL, min(QR, mid), val);
	Update(v << 1 | 1, mid + 1, R, max(QL, mid + 1), QR, val);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

pll Query(int v, int L, int R, int QL, int QR) {
	Push(v);
	if (QR < QL) return {0, L};
	if (QL == L && QR == R) return sg[v];

	int mid = (L + R) >> 1;
	return max(Query(v << 1, L, mid, QL, min(QR, mid)), 
			Query(v << 1 | 1, mid + 1, QR, max(QL, mid + 1), QR));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, v, r;
		cin >> l >> v >> r;
		L[l].push_back({v, r});
		V[v].push_back(r);	
		A[i] = {{l, r}, v};
	}
	
	Build(1, 1, N);
	int ans = 0, ans_l = 0, ans_r = 0;
	for (int l = 1; l < N; l++) {
		for (pll e : L[l])
			Update(1, 1, N, e.X, e.Y, 1);
		
		pll T = Query(1, 1, N, l, N);
		if (T.X > ans) {
			ans = T.X;
			ans_l = l;
			ans_r = T.Y;
		}

		for (int r : V[l]) Update(1, 1, N, l, r, -1);
	}
	
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if (A[i].X.X <= ans_l && A[i].X.Y >= ans_r && A[i].Y <= ans_r && A[i].Y >= ans_l)
			cout << i << sep;
	cout << endl;
	return 0;
}