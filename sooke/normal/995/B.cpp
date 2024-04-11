#include <cstdio>
#define Maxn 201

int n, m, ans, cnt, a[Maxn];
bool used[Maxn], vis[Maxn];

int main() {
	scanf("%d", &m);
	n = m << 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt = 0;
			for (int j = i + 1; j <= n; j++) {
				if (a[i] == a[j]) {
					ans += cnt;
					used[i] = used[j] = true;
					break;	
				} else if(!used[j]) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF995B Suit and Tie.