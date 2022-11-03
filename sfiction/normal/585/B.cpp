#include <cstdio>
#include <cstring>

const int MAXN = 1E2 + 10;

int n, k;
int f[MAXN][3];
char s[4][MAXN];

bool ava(int i, int j, int k){
	return (i + 2 * i - 4 > n || s[j][i + 2 * i - 4] == '.')
		&& (i + 2 * i - 4 > n || s[k][i + 2 * i - 4] == '.')
		&& (i + 2 * i - 3 > n || s[k][i + 2 * i - 3] == '.')
		&& (i + 2 * i - 2 > n || s[k][i + 2 * i - 2] == '.');
}

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		scanf("%d%d", &n, &k);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= 3; ++i){
			scanf("%s", s[i] + 1);
			if (s[i][1] == 's')
				f[1][i] = true;
		}
		
//		printf("%d %d %d\n", f[1][1], f[1][2], f[1][3]);
		for (int i = 2; i <= n; ++i){
			for (int j = 1; j <= 3; ++j)
				if (f[i - 1][j])
					for (int dj = -1; dj <= 1; ++dj)
						if (1 <= j + dj && j + dj <= 3)
							f[i][j + dj] |= ava(i, j, j + dj);
//			printf("%d %d %d\n", f[i][1], f[i][2], f[i][3]);
		}
		puts(f[n][1] || f[n][2] || f[n][3] ? "YES" : "NO");
	}
	return 0;
}