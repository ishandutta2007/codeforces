#include <cstdio>
#define G(x , y) (((x) - 1) * m + (y))
#define Min(x , y) ((x) < (y) ? (x) : (y))

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , m , k , l , r , t , a[1000001] , f[1000001] , w[1000001];

int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			a[G(i , j)] = Read();
	for(int j = 1 ; j <= m ; j++)
		f[G(1 , j)] = 1;
	for(int j = 1 ; j <= m ; j++)
		for(int i = 2 ; i <= n ; i++)
			if(a[G(i , j)] >= a[G(i - 1 , j)])
				f[G(i , j)] = f[G(i - 1 , j)];
			else
				f[G(i , j)] = i;
	for(int i = 1 ; i <= n ; i++){
		w[i] = 2147400000;
		for(int j = 1 ; j <= m ; j++)
			w[i] = Min(w[i] , f[G(i , j)]);
	}
	k = Read();
	for(int i = 1 ; i <= k ; i++){
		l = Read() , r = Read();
		if(w[r] <= l)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}