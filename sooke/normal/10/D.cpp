#include <cstdio>
#define Maxn 505
#define Max(x , y) ((x) > (y) ? (x) : (y))

int n , m , ans , a[Maxn] , b[Maxn] , f[Maxn][Maxn] , lsx[Maxn][Maxn] , lsy[Maxn][Maxn];

void Dfs(int x , int y){
	if(y == 0)
		return;
	Dfs(lsx[x][y] , lsy[x][y]);
	printf("%d " , b[y]);
}

int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	scanf("%d" , &m);
	for(int i = 1 ; i <= m ; i++)
		scanf("%d" , &b[i]);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 , _max = 0 ; j <= m ; j++){
			f[i][j] = f[i - 1][j];
			lsx[i][j] = lsx[i - 1][j];
			lsy[i][j] = lsy[i - 1][j];
			if(a[i] == b[j] && f[i][j] < f[i - 1][_max] + 1){
				f[i][j] = f[i - 1][_max] + 1;
				lsx[i][j] = i - 1;
				lsy[i][j] = _max;
			}
			if(b[j] < a[i] && f[i - 1][_max] < f[i - 1][j])
				_max = j;
		}
	for(int i = 1 ; i <= m ; i++)
		ans = Max(ans , f[n][i]);
	printf("%d\n" , ans);
	if(ans > 0)
		for(int i = 1 ; i <= m ; i++)
			if(ans == f[n][i]){
				Dfs(n , i);
				break;
			}
	return 0;
}

// By Sooke.
// CF10D LCIS.