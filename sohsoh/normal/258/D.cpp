#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ld H = 0.5;

ld D[MAXN][MAXN];
int n, A[MAXN], q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			D[i][j] = 1;
			if (A[i] > A[j]) swap(D[i][j], D[j][i]);
		}
	}

	while (q--) {
		int i, j;
		cin >> i >> j;

		for (int k = 1; k <= n; k++) {
			if (k == i || k == j) continue;
			ld d_k_i = D[k][i];
			D[k][i] = H * D[k][i] + H * D[k][j];
			D[i][k] = 1 - D[k][i];
			D[k][j] = H * D[k][j] + H * d_k_i;
			D[j][k] = 1 - D[k][j];
		}

		D[i][j] = H;
		D[j][i] = H;
	}	

	ld ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++) 
			ans += D[i][j];
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}