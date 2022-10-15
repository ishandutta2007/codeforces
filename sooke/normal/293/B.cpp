#include <cstdio>
#define Maxn 11
#define M(x) ((x) % 1000000007)
#define Lowbit(x) ((x) & -(x))

int n , m , k , g[Maxn][Maxn] , f[Maxn][Maxn] , cnt[Maxn] , lg[1 << Maxn];

int Dfs(int x , int y){
	if(y > m)
		x++ , y = 1;
	if(x > n)
		return 1;
	int res = 0;
	for(int tmp = -1 , pre = f[x - 1][y] & f[x][y - 1] , con = pre , col ; con > 0 ; con -= Lowbit(con)){
		col = lg[Lowbit(con)];
		f[x][y] = pre ^ Lowbit(con);
		if(g[x][y] == 0 || g[x][y] == col){
			if(cnt[col] == 0){
				cnt[col]++;
				res += tmp == -1 ? tmp = Dfs(x , y + 1) : tmp;
				cnt[col]--;
			}else
				res += Dfs(x , y + 1);
			res = M(res);
		}
	}
	return res;
}

int main(){
	scanf("%d%d%d" , &n , &m , &k);
	if(n + m > k + 1){
		printf("0\n");
		return 0;
	}
	for(int i = 1 ; i <= k ; i++)
		lg[1 << i - 1] = i;
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			f[i][j] = (1 << k) - 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++){
			scanf("%d" , &g[i][j]);
			if(g[i][j] != 0)
				cnt[g[i][j]]++;
		}
	printf("%d\n" , Dfs(1 , 1));
	return 0;
}

// By Sooke.
// CF293B Distinct Paths.