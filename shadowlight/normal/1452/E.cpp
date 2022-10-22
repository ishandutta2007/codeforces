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

ll add[N][N];
ll adde[N][N];

int intersection(int l1, int r1, int l2, int r2) {
	return max(min(r1, r2) - max(l1, l2) + 1, 0);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		for (int i = 1; i <= n; ++i) {
			int cnt = intersection(i, i + k - 1, l, r);
			int a = 0, b = l + cnt - k;
			if (a <= b) {
				add[i][a] += cnt;
				add[i][b] -= cnt;	
			}
			if (a <= b + 1) {
				adde[i][a] += cnt;
				adde[i][b + 1] -= cnt;
			}

			int c = r - cnt + 1, d = n + 1;
			/*if (i == 3 || i == 4) {
				cout << "CNT: " << cnt << " " << i << " " << l << " " << r << " " << a << " " << b << " " << c << " " << d << "\n";
			}*/
			if (c + 1 <= d) {
				add[i][c + 1] += cnt;
				add[i][d] -= cnt;
			}
			if (c <= d) {
				adde[i][max(b + 1, c)] += cnt;
				adde[i][d] -= cnt;
			}

			if (cnt == min(r - l + 1, k) && b + 1 <= c) {
				adde[i][max(b + 1, 0)] += cnt;
				adde[i][c] -= cnt;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < N; ++j) {
			add[i][j] += add[i][j - 1];
			adde[i][j] += adde[i][j - 1];
		}
	}

	//cout << add[1][2] << " " << adde[2][1] << "\n";

	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ll now = add[i][j] + adde[j][i];
			res = max(res, now);
			//cout << i << " " << j << " " << now << "\n";
		}
	}
	cout << res << "\n";

}