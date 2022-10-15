#include <cstdio>
#include <cstring>
#define Min(x , y) ((x) < (y) ? (x) : (y))

int t , n , m , c , f[31][31][901];

int main(){
	memset(f , 60 , sizeof(f));
	for(int i = 1 ; i <= 30 ; i++)
		for(int j = 1 ; j <= 30 ; j++)
			f[i][j][i * j] = f[i][j][0] = 0;
	for(int i = 1 ; i <= 30 ; i++)
		for(int j = 1 ; j <= 30 ; j++)
			for(int k = 1 ; k <= 50 ; k++){
				for(int h = 1 ; h < i ; h++){
					f[i][j][k] = Min(f[i][j][k] , f[h][j][k] + j * j);
					if(k - (i - h) * j >= 0)
						f[i][j][k] = Min(f[i][j][k] , f[h][j][k - (i - h) * j] + j * j);
				}
				for(int h = 1 ; h < j ; h++){
					f[i][j][k] = Min(f[i][j][k] , f[i][h][k] + i * i);
					if(k - (j - h) * i >= 0)
						f[i][j][k] = Min(f[i][j][k] , f[i][h][k - (j - h) * i] + i * i);
				}
			}
	for(scanf("%d" , &t) ; t >= 1 ; t--){
		scanf("%d%d%d" , &n , &m , &c);
		printf("%d\n" , f[n][m][c]);
	}
	return 0;
}