#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int a[maxn], b[maxn];
int main(){
	int n, h; scanf("%d%d", &n, &h);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++)
			b[j] = a[j];
		sort(b + 1, b + 1 + i);
		long long t = 0;
		for(int j = i; j > 0; j -= 2)
			t += b[j];
		if(t <= h) ans = i;
	}
	printf("%d\n", ans);
	return 0;
}