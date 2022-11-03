#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0, len = 0;
	int pre = 0, now;
	for (int i = 0; i < n; ++i){
		scanf("%d", &now);
		len = pre <= now ? len + 1 : 1;
		ans = max(ans, len);
		pre = now;
	}
	printf("%d\n", ans);
	return 0;
}