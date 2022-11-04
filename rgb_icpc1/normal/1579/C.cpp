#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 500005;

int Tc, N;
bool dark[20][20], vis[20][20];
char s[20];
bool ok(int i, int j, int d) {
	for(int k = 0 ; k <= d ; k ++) if(!dark[i - k][j - k]) return 0;
	for(int k = 0 ; k <= d ; k ++) if(!dark[i - k][j + k]) return 0;
	return 1;
}
void calc(int i, int j, int d) {
	for(int k = 0 ; k <= d ; k ++) vis[i - k][j - k] = 1, vis[i - k][j + k] = 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j, n, m, k;
	for (cin >> Tc; Tc--; ) {
		memset(dark, 0, sizeof dark);
		memset(vis, 0, sizeof vis);
		cin >> n >> m >> k;
		for(i = 0 ; i < n ; i ++) {
			cin >> s;
			for(j = 0 ; j < m ; j ++) if(s[j] == '*') dark[i][j] = 1;
		}
		for(i = 0 ; i < n ; i ++) {
			for(j = 0 ; j < m ; j ++) {
				if(vis[i][j]) continue;
				if(dark[i][j]) {
					if(i < k || m - j - 1 < k) continue;
					for(int d = k ; d <= min(i, m -j - 1) ; d ++) {
						if(ok(i, j, d)) calc(i, j, d);
					}
				}
			}
		}
		bool valid = 1;
		for(i = 0 ; i < n ; i ++) {
			for(j = 0 ; j < m ; j ++) {
				if(dark[i][j] != vis[i][j]) {
					valid = false;
					break;
				}
			}
		}
		cout << ((valid == 1) ? "YES" : "NO") << endl;
	}

	return 0;

}