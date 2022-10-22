#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1007;
const int M = 17;
const int MOD = 1e9 + 7;

int C[N][M];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			//cout << i << " " << j << " " << C[i][j - 1] << "\n";
			for (int ni = i; ni < N; ni++) {
				add(C[ni][j], C[i][j - 1]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			add(res, C[i][m - 1] * (ll) C[n - j + 1][m - 1] % MOD);
		}
	}
	cout << res << "\n";

}