#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int n, b[N], ind[N], q[N], l = 1, r;
long long a[N], ans;

void dfs(int i){
	ans += a[i];
	if(a[i] > 0){
		a[b[i]] += a[i];
		q[l++] = i;
	}else q[r--] = i;
	if(!--ind[b[i]]) dfs(b[i]);
	ind[i] = -1;
}

int main(){
	scanf("%d", &n);
	r = n;
	for(int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	for(int i = 1; i <= n; i++){
		scanf("%d", b + i);
		if(b[i] != -1) ind[b[i]]++;
	}
	for(int i = 1; i <= n; i++)
		if(ind[i] == 0) dfs(i);
	printf("%lld\n", ans);
	for(int i = 1; i <= n; i++)
		printf("%d ", q[i]);
	return 0;
}