#include <bits/stdc++.h>
using namespace std;

#define N 404040

set <int> S;
set <int> :: iterator it;
int a[N], n, k;
int last[N], nxt[N];

void pop() {
	it = S.end();
	it --;
	S.erase(it);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) last[i] = n + 1;
	for (int i = n; i >= 1; i --) {
		nxt[i] = last[a[i]];
		last[a[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		it = S.find(i);
		if (it == S.end()) {
			ans ++;
			if (S.size() >= k) pop();
		}
		else S.erase(it);
		if (nxt[i] != n + 1) S.insert(nxt[i]);
		if (S.size() > k) pop();
	}
	printf("%d\n", ans);

	return 0;
}