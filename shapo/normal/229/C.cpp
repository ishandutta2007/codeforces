#include <cstdio>

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define maxn 1005000

int n, m, a, b;
int count[maxn];
long long res, bad;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &a, &b);
		++count[a];
		++count[b];
	}
	res = n;
	res = (res - 2) * (res - 1) * res / 6;
	for(int i = 1; i <= n; ++i)
		bad += (long long)(n - count[i] - 1) * count[i];
	res = res - bad / 2;
	printf(LLD"\n", res);
	return 0;
}