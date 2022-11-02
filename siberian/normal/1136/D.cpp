#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m;
const int MAXN = 3 * 1e5 + 10;
int p[MAXN];
set <int> arr[MAXN];
set <int> good, help;

void read() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		if (u == p[n]) {
			good.insert(v);
		}
		else {
			arr[u].insert(v);
		}
	}
}
int ans = 0;
void run() {
	int cnt = 0;
	for (int i = n - 1; i >= 1; i--) {
		if (good.find(p[i]) != good.end()) {
			if (cnt == 0 || help.find(p[i]) != help.end()) {
				ans++;
			}
			else {
				cnt++;
				set <int> help2;
				for (auto j : arr[p[i]]) {
					if (help.find(j) != help.end()) {
						help2.insert(j);
					}
				}
				help = help2;
			}
		}
		else {
			set <int> help2;
			if (cnt == 0) {
				help = arr[p[i]];
			}
			else {
				for (auto j : arr[p[i]]) {
					if (help.find(j) != help.end()) {
						help2.insert(j);
					}	
				}
				help = help2;	
			}
			cnt++;
		}
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}