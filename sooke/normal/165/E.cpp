#include <cstdio>
#include <cstring>
#define Maxn 1000001
#define Maxc 4200001
#define Max(x , y) ((x) > (y) ? (x) : (y))

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , h , _max , M , a[Maxn] , f[Maxc];

int main(){
	n = Read();
	memset(f , -1 , sizeof(f));
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		_max = Max(_max , a[i]);
		f[a[i]] = a[i];
	}
	for(int i = 0 ; i <= 22 ; i++)
		if(_max & (1 << i))
			h = i;
	M = (1 << h + 1) - 1;
	for(int i = 0 ; i <= h ; i++)
		for(int j = 2 ; j <= M ; j++)
			if(j & (1 << i))
				f[j] = Max(f[j] , f[j ^ (1 << i)]);
	for(int i = 1 ; i <= n ; i++)
		printf("%d " , f[M ^ a[i]]);
	return 0;
}

// By Sooke.
// CF165E Compatible Numbers.