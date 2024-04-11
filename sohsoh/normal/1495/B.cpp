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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int P[MAXN], n, L[MAXN], R[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> P[i];
	L[1] = R[n] = 0;
	for (int i = 2; i <= n; i++) {
		if (P[i - 1] < P[i]) L[i] = L[i - 1] + 1;
		else L[i] = 0;
	}

	for (int i = n - 1; i > 0; i--) {
		if (P[i + 1] < P[i]) R[i] = R[i + 1] + 1;
		else R[i] = 0;
	}

	int mx_path = 0, mx_path_cnt = 0, mx_h = 0, diff = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		int p = max(L[i], R[i]);
		if (p > mx_path) {
			mx_path = p;
			mx_path_cnt = 1;
			flag = true;
		} else if (p == mx_path)
			mx_path_cnt++;
		if (L[i] == 0 || R[i] == 0) continue;
		if (p > mx_h) {
			mx_h = p;
			if (p == 2 && L[i] + R[i] == 3) flag = false;
			diff = abs(R[i] - L[i]);
		}
	}

	if (mx_path_cnt > 1 || mx_path > mx_h || mx_h % 2 == 1 || diff >= 1) return cout << 0 << endl, 0;
	cout << 1 << endl;
	return 0;
}