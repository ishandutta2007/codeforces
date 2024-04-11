// \_()_/
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

const ll MAXN = 1e5 + 10; // TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 18;

int LOG_TB[MAXN], n, q, K[MAXN], LA[MAXN], RA[MAXN], LB[MAXN], RB[MAXN], mx_a[MAXN], mx_b[MAXN];
pair<int, bool> dp[MAXN][2];

struct SparseTable {
	int SP[MAXN][LOG], n;
	bool C = false;

	SparseTable() {}
	SparseTable(int* A, int tn, bool B) {
		n = tn;
		C = B;
		for (int i = 0; i <= n; i++) SP[i][0] = A[i];
		for (int j = 1; j < LOG; j++) {
			for (int i = 0; i <= n; i++) {
				int ti = min(i + (1 << (j - 1)), n);
				if (C) SP[i][j] = max(SP[i][j - 1], SP[ti][j - 1]);
				else SP[i][j] = min(SP[i][j - 1], SP[ti][j - 1]);
			}
		}
	}

	int Query(int L, int R) {
		int g = LOG_TB[R - L + 1];
		if (C) return max(SP[L][g], SP[R - (1 << g) + 1][g]);
		else return min(SP[L][g], SP[R - (1 << g) + 1][g]);
	}
};

SparseTable la, lb, ra, rb;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 2; i < MAXN; i++) LOG_TB[i] = LOG_TB[i / 2] + 1;

	for (int i = 1; i <= n; i++) cin >> K[i] >> LA[i] >> RA[i] >> LB[i] >> RB[i];
	la = SparseTable(LA, n, true);
	lb = SparseTable(LB, n, true);
	ra = SparseTable(RA, n, false);
	rb = SparseTable(RB, n, false);

	

	for (int i = 0; i <= n; i++) {
		int L = i, R = n + 1;
		while (L < R) {
			int mid = (L + R) >> 1;
			if (mid == n + 1) {
				L = R = n + 1;
				break;
			}

			if (la.Query(i, mid) > K[i] || ra.Query(i, mid) < K[i]) R = mid;
			else L = mid + 1;
		}
		mx_a[i] = L;

		L = i, R = n + 1;
		while (L < R) {
			int mid = (L + R) >> 1;
			if (mid == n + 1) {
				L = R = n + 1;
				break;
			}

			if (lb.Query(i, mid) > K[i] || rb.Query(i, mid) < K[i]) R = mid;
			else L = mid + 1;
		}
		mx_b[i] = L;
	}
	
	dp[0][0] = {mx_b[0], false};
	dp[0][1] = {mx_a[0], false};
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = {-1, false};
		if (mx_a[i] > i && dp[i - 1][0].X > i) dp[i][0] = {dp[i - 1][0].X, false};
		if (mx_a[i] > i && mx_b[i - 1] > max(i, dp[i][0].X) && dp[i - 1][1].X > i - 1) dp[i][0] = {mx_b[i - 1], true};

		if (mx_b[i] > i && dp[i - 1][1].X > i) dp[i][1] = {dp[i - 1][1].X, false};
		if (mx_b[i] > i && mx_a[i - 1] > max(i, dp[i][1].X) && dp[i - 1][0].X > i - 1) dp[i][1] = {mx_a[i - 1], true};
	}
	

	int ind = 2;
	if (dp[n][1].X > n) ind = 1;
	if (dp[n][0].X > n) ind = 0;
	if (ind == 2) return cout << "No" << endl, 0;
	cout << "Yes" << endl;
	
	stack<int> st;
	while (n > 0) {
		st.push(ind);
		if (dp[n][ind].Y) ind = 1 - ind;
		n--;
	}

	while (!st.empty()) {
		cout << st.top() << sep;
	       	st.pop();
	}

	cout << endl;
	return 0;
}