#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2007;
const int MOD = 998244353;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int C[N][N];
int ways[N][N], sufs[N][N];

void init() {
	C[0][0] = 1;
	for (int i = 1; i < N; i++) {
		C[i][0] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j];
			add(C[i][j], C[i - 1][j - 1]);
		}
		C[i][i] = 1;
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	string s;
	cin >> s;
	int n = s.size();
	ways[n][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= n; j++) {
			if (s[i] != '(') {
				add(ways[i][j + 1], ways[i + 1][j]);
			}
			if (s[i] != ')') {
				add(ways[i][j], ways[i + 1][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = N - 2; j >= 0; j--) {
			sufs[i][j] = sufs[i][j + 1];
			add(sufs[i][j], ways[i][j]);
		}
	}
	int q = 0, open = 0;
	int res = 0;
	for (int pos = 0; pos < n; pos++) {
		char c = s[pos];
		if (c == ')') continue;
		for (int cnt = open + 1; cnt <= n; cnt++) {
			add(res, C[q][cnt - open - 1] * (ll) sufs[pos + 1][cnt] % MOD);
		}
		if (c == '?') {
			q++;
		} else {
			open++;
		}
	}
	cout << res << "\n";
	
}