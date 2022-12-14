#include <bits/stdc++.h>
using namespace std;

#define N 400040

int n, k, a[N], b[N], nx[N], rmh, ans, cnt;
bool vis[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		b[i] = i + n;
	}
	for (int i = n; i >= 1; i --) {
		nx[i] = b[a[i]];
		b[a[i]] = i;
	}
	set<int> S;
	set<int>::iterator it;
	for (int i = 1; i <= n; i ++) {
		if (S.find(i) != S.end()) {
			S.erase(i);
			S.insert(nx[i]);
		}
		else {
			ans ++;
			if (cnt < k) {
				cnt ++;
				vis[a[i]] = 1;
			}
			else {
				it = S.end();
				it --;
				S.erase(it);
			}
			S.insert(nx[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}