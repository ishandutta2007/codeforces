#include <cstdio>
#include <algorithm>
using namespace std;

long long a[2000005];
int n;

inline int max(int a, int b){
	return a>b?a:b;
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	a[n+1] = 0x7fffffffffffffLL;
	int ans = 1, start = 1;
	for(int i=2; i<=n; i++){
		if(a[i] <= a[i-1] * 2) ans = max(ans, i - start + 1);
		else start = i;
	}
	printf("%d\n", ans);
	return 0;
}