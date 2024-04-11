#include <cstdio>
#define Maxn 20

int n , m , M;
long long ans , f[Maxn][1 << Maxn - 1];
bool edg[Maxn][Maxn];

int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= m ; i++){
		int u , v;
		scanf("%d%d" , &u , &v);
		edg[u][v] = edg[v][u] = true;
	}
	for(int i = 1 ; i <= n ; i++)
		f[i][1 << i - 1] = 1;
	M = (1 << n) - 1;
	for(int i = 1 ; i <= M ; i++){
		int st;
		for(int j = 1 ; j <= n ; j++)
			if((1 << j - 1) & i){
				st = j;
				break;
			}
		for(int j = 1 ; j <= n ; j++){
			if((1 << j - 1) & i)
				if(edg[j][st] && (i ^ (1 << st - 1) ^ (1 << j - 1)) > 0)
					ans += f[j][i];
			for(int k = st + 1 ; k <= n ; k++)
				if((1 << k - 1) & i);else
					if(edg[j][k])
						f[k][(1 << k - 1) | i] += f[j][i];
		}
	}
	printf("%lld\n" , ans >> 1);
	return 0;
}

// By Sooke.
// CF11D A Simple Task.