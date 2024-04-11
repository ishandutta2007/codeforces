#include <cstdio>

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , m , a[1000001];
bool f[1002][1002];

int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++)
		a[i] = Read() , a[i] = a[i] % m;
	if(n > m){
		printf("YES\n");
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){
		f[i][a[i]] = true;
		for(int j = 0 ; j < m ; j++)
			if(f[i - 1][j])
				f[i][j] = f[i][(j + a[i]) % m] = true;
		if(f[i][0]){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}