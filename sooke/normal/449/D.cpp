#include <cstdio>
#define P 1000000007
#define Maxn 1000005
#define Maxc 2050000
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

int n , h , M , _max , a[Maxn] , pow[Maxn] , f[Maxc] , sig[Maxc];
long long ans;

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		_max = Max(_max , a[i]);
	}
	pow[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		pow[i] = (pow[i - 1] << 1) % P;
	for(int i = 0 ; i <= 19 ; i++)
		if(_max & (1 << i))
			h = i;
	M = (1 << h + 1) - 1;
	for(int i = 1 ; i <= n ; i++)
		f[M ^ a[i]]++;
	for(int i = 0 ; i <= h ; i++)
		for(int j = 1 ; j <= M ; j++)
			if(j & (1 << i))
				f[j] += f[j ^ (1 << i)];
	sig[0] = (h & 1) ? 1 : -1;
	for(int i = 0 ; i <= M ; i++){
		if(i & 1)
			sig[i] = -sig[i >> 1];
		else
			sig[i] = sig[i >> 1];
		ans = (ans + sig[i] * pow[f[i]]) % P;
	}
	printf("%lld\n" , (ans + P) % P);
	return 0;
}

// By Sooke.
// CF449D Jzzhu and Numbers.