#include <cstdio>
#define Maxn 1000005
#define Min(x , y) ((x) < (y) ? (x) : (y))
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

int n , k , ans , f[Maxn] , pre[Maxn];

int main(){
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i++)
		f[1000001 - Read()]++;
	for(int i = 1 ; i <= 1000000 ; i++)
		if(f[i] > 0){
			pre[i + 1]++;
			pre[Min(i + k + 1 , 1000001)]--;
		}
	for(int i = 1 ; i <= 1000000 ; i++){
		pre[i] += pre[i - 1];
		if(pre[i] == 0)
			ans += f[i];
	}
	printf("%d\n" , ans);
	return 0;
}

// By Sooke.
// CF990B Micro-World.