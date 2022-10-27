#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int t, n;
char s[N][N]; int ok[N][N];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
			bool gg = 0;
		for (int i = n; i >= 1; i --) {
			if (gg) break;
			for (int j = n; j >= 1; j --) {
				if (gg) break;
				if (s[i][j] == '1') {
					if (i == n || j == n) continue;
					if (s[i+1][j] == '1' || s[i][j+1]=='1') continue;
					printf("NO\n"); gg = 1;
				}
			}
		}
		if (gg == 0) printf("YES\n");
	}
}