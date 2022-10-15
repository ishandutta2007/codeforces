#include <cstdio>
#define Maxn 100005
#define Max(x , y) ((x) > (y) ? (x) : (y))
#define Min(x , y) ((x) < (y) ? (x) : (y))

inline int Read(){
	char c = getchar();
	int n = 0 , f = 0;
	while(c < '0' || c > '9'){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return f ? -n : n;
}

int n , sum , ans , a[Maxn] , pre[Maxn] , suf[Maxn];

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i = n ; i >= 1 ; i--){
		suf[i] = suf[i + 1] + a[i];
		suf[i + 1] = Min(suf[i + 1] , suf[i + 2]);
	}
	suf[1] = Min(suf[1] , suf[2]);
	sum = pre[n];
	for(int i = 0 ; i <= n ; i++)
		ans = Max(ans , sum - (pre[i] + suf[i + 1]) * 2);
	printf("%d\n" , ans);
	return 0;
}

// By Sooke.
// CF33C Wonderful Randomized Sum