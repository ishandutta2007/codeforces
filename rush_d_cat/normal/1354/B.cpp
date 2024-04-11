#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int t;
char s[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int nex[4] = {0}, res = N;
		for (int i = 1; i <= n; i ++) s[i] --;
		for (int i = n; i >= 1; i --) {
			nex[s[i] - '0'] = i;
			int mn = N, mx = 0;
			for (int j = 0; j < 3; j ++) {
				//printf("%d ", nex[j]);
				mn = min(mn, nex[j]);
				mx = max(mx, nex[j]);
			}
			//printf("\n");
			if (mn == 0) continue;
			//printf("%d %d\n", mn, mx);
			res = min(res, mx - i + 1);
		}
		if (res == N) res = 0;
		printf("%d\n", res);
	}
}