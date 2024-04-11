#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200100;
int a[maxn], b[maxn];
int main(){
	int n, m, ta, tb, k;
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int j = 1; j <= m; ++j)
		scanf("%d", &b[j]);
	if(k >= n)
		printf("-1\n");
	else{
		int ans = 0;
		for(int i = 0, j = 1; i <= k; ++i){
			while(j <= m && a[i + 1] + ta > b[j]) ++j;
			if(j + k - i > m){
				ans = -1;
				break;
			}
			ans = max(ans, b[j + k - i] + tb);
		}
		printf("%d\n", ans);
	}
	return 0;
}