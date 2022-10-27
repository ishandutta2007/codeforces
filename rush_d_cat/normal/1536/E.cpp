#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const int N = 2002;
const int mod = 1e9 + 7;
int n, m;
char s[N][N];
int main() {
	int t; scanf("%d", &t);
	while (t --) {
		int n, m; scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s[i] + 1);
		}
		int a = 1, c = 0;
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (s[i][j] == '#') {
			a = a * 2 % mod; c ++;
		}
		if (c == 0) {
			printf("%d\n", 1);
		} else {
			if (c == n * m)
			a = (a - 1 + mod) % mod;
			printf("%d\n", a);
		}
	}	
}