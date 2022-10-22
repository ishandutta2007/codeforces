#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], X[MAXN];
pll D[MAXN];
bool ok[MAXN];

void solve() {
	int n;
	cin >> n;
	fill(X, X + n + 10, 0);
	for (int i = 0; i < n; i++) cin >> A[i];
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && A[st.top()] >= A[i]) st.pop();
		if (st.empty()) D[i].X = 0;
		else D[i].X = st.top() + 1;
		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && A[st.top()] >= A[i]) st.pop();
		if (st.empty()) D[i].Y = n - 1;
		else D[i].Y = st.top() - 1;
		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		X[A[i]] = max(1ll * X[A[i]], D[i].Y - D[i].X + 1);
	}

	int req = INF;
	for (int i = 1; i <= n; i++) {
		req = min(req, X[i]);
		if (req >= (n - i + 1)) ok[(n - i + 1)] = true;
		else ok[n - i + 1] = false;
	}

	for (int i = 1; i <= n; i++) {
		if (ok[i]) cout << 1;
		else cout << 0;
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}