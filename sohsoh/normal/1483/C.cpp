#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int sg[MAXN], H[MAXN], B[MAXN], n;

void Update(int v, int L, int R, int ind, int val) {
	if (L == R) {
		sg[v] = val;
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(v << 1, L, mid, ind, val);
	else Update(v << 1 | 1, mid + 1, R, ind, val);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

int Query(int v, int L, int R, int ql, int qr) {
	if (qr < ql) return -INF;
	if (ql == L && qr == R) return sg[v];

	int mid = (L + R) >> 1;
	return max(Query(v << 1, L, mid, ql, min(mid, qr)), Query(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr));
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> H[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	stack<int> st;
	for (int i = 1; i <= n; i++) {
		int L = 1, prev_dp = -INF;

		while (!st.empty() && H[st.top()] > H[i]) st.pop();
		if (!st.empty()) L = st.top() + 1, prev_dp = Query(1, 1, n, st.top(), st.top());
		st.push(i);
		
		Update(1, 1, n, i, max({Query(1, 1, n, max(1ll, L - 1), i - 1) + B[i], prev_dp, int(L != 1) * -INF + B[i]}));
	}
	
	cout << Query(1, 1, n, n, n) << endl;
	return 0;
}