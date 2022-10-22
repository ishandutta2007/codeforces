#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;

void add(int &x, int y) {
	 x += y;
	 if (x >= MOD) {
	 	x -= MOD;
	 }
}

const int N = 3607;

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int rev(int a) {
	return power(a, MOD - 2);
}

int dph[N][N][2];
int dpw[N][N][2];
bool uh[N], uw[N];

int f[N], rf[N];

void init() {	
	f[0] = 1, rf[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * (ll) i % MOD;
		rf[i] = rev(f[i]);
	}
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * (ll) rf[n - k] % MOD;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		uh[a] = true;
		uh[c] = true;
		uw[b] = true;
		uw[d] = true;
	}
	uh[0] = true, uw[0] = true;
	dph[0][0][1] = 1;
	for (int i = 1; i <= h; i++) {
		for (int cnt = 0; cnt <= h; cnt++) {
			for (int d = 0; d < 2; d++) {
				add(dph[i][cnt][uh[i]], dph[i - 1][cnt][d]);
			}
			if (!uh[i] && !uh[i - 1]) {
				add(dph[i][cnt + 1][1], dph[i - 1][cnt][0]);
			}
		}
	}
	dpw[0][0][1] = 1;
	for (int i = 1; i <= w; i++) {
		for (int cnt = 0; cnt <= w; cnt++) {
			for (int d = 0; d < 2; d++) {
				add(dpw[i][cnt][uw[i]], dpw[i - 1][cnt][d]);
			}
			if (!uw[i] && !uw[i - 1]) {
				add(dpw[i][cnt + 1][1], dpw[i - 1][cnt][0]);
			}
		}
	}
	int fh = 0, fw = 0;
	for (int i = 1; i <= h; i++) {
		if (!uh[i]) fh++;
	}
	for (int i = 1; i <= w; i++) {
		if (!uw[i]) fw++;
	}
	int res = 0;
	for (int a = 0; a <= h; a++) {
		for (int b = 0; b <= w; b++) {
			int suma = (dph[h][a][0] + dph[h][a][1]) % MOD;
			int sumb = (dpw[w][b][0] + dpw[w][b][1]) % MOD;
			int now = suma * (ll) sumb % MOD;
			if (!now) continue;
			now = now * (ll) C(fh - 2 * a, b) % MOD;
			now = now * (ll) C(fw - 2 * b, a) % MOD;
			//cout << a << " " << b << " " << dph[h][a] << "\n";
			add(res, now);
		}
	}
	cout << res << "\n";
}