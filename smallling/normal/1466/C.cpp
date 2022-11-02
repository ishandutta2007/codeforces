#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int f[N][2][2];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		for(int i = 0; i <= n; i++)
			for(int x = 0; x < 2; x++)
				for(int y = 0; y < 2; y++)
					f[i][x][y] = n + 1;
		f[0][0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int x = 0; x < 2; x++)
				for(int y = 0; y < 2; y++)
					for(int z = 0; z < 2; z++) {
						if(i > 1 && s[i] == s[i - 1] && !(y || z))continue;
						if(i > 2 && s[i] == s[i - 2] && !(x || z))continue;
						f[i][y][z] = min(f[i][y][z], f[i - 1][x][y] + z);
					}
		int ans = n + 1;
		for(int x = 0; x < 2; x++)
			for(int y = 0; y < 2; y++)
				ans = min(ans, f[n][x][y]);
		printf("%d\n", ans);
	}
}