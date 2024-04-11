#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, x[N], y[N], nxt[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) nxt[i] = 0;
		for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &y[i]), nxt[x[i]] = y[i];
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (!nxt[i]) continue;
			if (nxt[i] == i) continue;
			vector <int> vec;
			vec.push_back(i);
			int j = nxt[i];
			while (1) {
				vec.push_back(j);
				if (j == i) {
					ans ++; break;
				}
				if (!nxt[j]) break;
				j = nxt[j];
			}
			ans += vec.size() - 1;
			for (auto x : vec) nxt[x] = 0;
		}
		printf("%d\n", ans);
    }


    return 0;
}