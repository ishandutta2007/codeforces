#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, cnt[N];
vector <int> vec[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i ++) vec[i].clear();
		for (int i = 1; i <= n; i ++) cnt[i] = 0;
		for (int i = 0; i < m; i ++) {
			int sz;
			scanf("%d", &sz);
			vec[i].resize(sz);
			for (auto &x : vec[i]) scanf("%d", &x);
			if (sz == 1) cnt[vec[i][0]] ++;
		}
		vector <int> ans;
		for (int i = 0; i < m; i ++) {
			int sz = vec[i].size();
			if (sz == 1) ans.push_back(vec[i][0]);
			else {
				int k = *min_element(vec[i].begin(), vec[i].end(), [&](int i, int j) {return cnt[i] < cnt[j];});
				cnt[k] ++, ans.push_back(k);
			}
		}
		if (*max_element(cnt + 1, cnt + n + 1) > (m + 1) / 2) puts("NO");
		else {
			puts("YES");
			for (int i = 0; i < m; i ++) printf("%d ", ans[i]); puts("");
		}
    }

    return 0;
}