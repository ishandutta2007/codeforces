#include <stdio.h>

#define M 155
#define mo 1000000007

int n, m, f[M][M], g[M][M], sf[M][M], tf[M][M], sg[M][M], tg[M][M];
int ssf[M][M], ssg[M][M], ttg[M][M];
int a[M][M], ans;

void init(){
	for(int i = 1; i < M; i ++)a[i][1] = 1;
	for(int j = 2; j < M; j ++){
		for(int i = 1; i < M; i ++){
			a[i][j] = 1;
			for(int k = 1; k <= i; k ++){
				a[i][j] += 1LL * (i + 1 - k) * a[k][j-1] % mo;
				if(a[i][j] >= mo)a[i][j] -= mo;
			}
		}
	}
}

inline void O(int &x){if(x >= mo) x -= mo;}
inline void P(int &x){if(x < 0) x += mo;}

void update(int t){
	for(int i = 1; i <= n; i ++)for(int j = i; j <= n; j ++){
		ans += f[i][j]; O(ans);
	}
	for(int i = 1; i <= n; i ++){
		sf[i][i] = f[i][i];
		for(int j = i + 1; j <= n; j ++){
			sf[i][j] = f[i][j] + sf[i][j-1]; O(sf[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++){
		sg[1][i] = g[1][i];
		for(int j = 2; j <= i; j ++){
			sg[j][i] = sg[j-1][i] + g[j][i]; O(sg[j][i]);
		}
	}
	for(int i = 1; i <= n; i ++)for(int j = i; j <= n; j ++){
		ssf[i][j] = sf[i][n];
		if(j > i)ssf[i][j] -= sf[i][j-1]; P(ssf[i][j]);
		if(i < j){
			ssg[i][j] = sg[n-i][n-i] - sg[j-i-1][n-i]; P(ssg[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++){
		tf[i][i] = ssf[i][i];
		for(int j = i - 1; j; j --){
			tf[i][j] = tf[i][j + 1] + ssf[j][i]; O(tf[i][j]);
			tg[i][j] = tg[i][j + 1] + ssg[j][i]; O(tg[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			f[i][j] = (tf[j][1] + 1) % mo;
			if(j > i)f[i][j] -= tf[j][i + 1]; P(f[i][j]);
			f[i][j] += tg[j][i]; O(f[i][j]);
			f[i][j] += tg[n-i+1][n-j+1]; O(f[i][j]);
			if(j>i+1)f[i][j] += a[j-i-1][t+1] - 1; O(f[i][j]); P(f[i][j]);
		}
	}
	for(int i = 1; i < n; i ++){
		for(int j = i; j < n; j ++){
			g[i][j] = (tg[n + i - j][n - j] + 1) % mo;
			if(i > 1)g[i][j] += a[i - 1][t+1] - 1; O(g[i][j]); P(g[i][j]);
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	init();
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++)for(int j = i; j <= n; j ++){
		f[i][j] = 1; g[i][j] = 1;
	}
	for(int t = 1; t <= m; t ++)update(t);
	printf("%d\n",ans);
	return 0;
}