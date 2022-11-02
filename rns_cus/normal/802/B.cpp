#include <bits/stdc++.h>
using namespace std;

#define N 400010

int nxt[N], a[N], vis[N], n, k;

set <int> S;
set <int> :: iterator it;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	for (int i = n; i >= 1; i --) {
		if (!vis[a[i]]) nxt[i] = i + n;
		else nxt[i] = vis[a[i]];
		vis[a[i]] = i;
	}

	int ans = 0, sz = 0;

	for (int i = 1; i <= n; i ++) {
		if ( S.find(i) == S.end() ) {
			ans ++;
			if( sz == k) S.erase(--S.end()), sz --;
			S.insert(nxt[i]), sz ++;
		}
		else {
			S.erase(i);
			S.insert(nxt[i]);
		}
	}
	cout << ans << endl;
}