#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], id[N], x[N];
long long ans;

bool cmp(int x, int y){
	return a[x] > a[y];
}

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			id[i] = i;
		}
		sort(id + 1, id + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			x[id[i]] = ((i & 1) ? -1 : 1) * ((i + 1) >> 1);
			ans += (long long)(i + (i & 1)) * a[id[i]];
		}
		printf("%lld\n0", ans);
		for(int i = 1; i <= n; i++)
			printf(" %d", x[i]);
		putchar('\n');
	}
	return 0;
}