#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, w[N], deg[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), deg[i] = 0;
		for (int i = 1, u, v; i < n; i ++) {
			scanf("%d %d", &u, &v);
			deg[u] ++, deg[v] ++;
		}
		vector <int> vec;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			ans += w[i];
			while (deg[i] > 1) vec.push_back(w[i]), deg[i] --;
		}
		sort(vec.begin(), vec.end());
		for (int k = 1; k < n; k ++) {
			printf("%lld ", ans);
			if (!vec.empty()) ans += vec.back(), vec.pop_back();
		}
		puts("");
    }

    return 0;
}