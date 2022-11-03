#include <cstdio>

const int MAXM = 1E3 + 10;

bool f[MAXM][MAXM];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n && i <= m; ++i){
		int t;
		scanf("%d", &t);
		t %= m;
		for (int j = 1; j < m; ++j)
			f[i][(t + j) % m] = f[i - 1][(t + j) % m] | f[i - 1][j];
		f[i][t] = true;
	}
	puts(f[n < m ? n : m][0] ? "YES" : "NO");
	return 0;
}