#include <bits/stdc++.h>
using namespace std;
#define N 100100

long long s, x[N], y[N];
int n;
bool vis[N];

int main() {
//	freopen("a.in", "r", stdin);
	cin >> s >> n;
	for (int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
	while (1) {
		bool chk = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) continue;
			if (s > x[i]) {
				vis[i] = 1, s += y[i];
				chk = 1;
			}
		}
		if (!chk) break;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			puts("NO"); return 0;
		}
	}
	puts("YES");
	return 0;
}