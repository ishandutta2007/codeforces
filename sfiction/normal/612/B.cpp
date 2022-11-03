#include <cstdio>
#include <cstdlib>

const int MAXN = 2E5 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		a[t] = i;
	}
	long long cnt = 0;
	for (int i = 1; i < n; ++i)
		cnt += abs(a[i] - a[i + 1]);
	printf("%I64d\n", cnt);
	return 0;
}