#include <stdio.h>
const int maxn = 300100;
int a[maxn], b[maxn];
bool Solve(int mid, int n, int m){
	for(int i = 1; i <= n; ++i){
		if(b[i-1] > a[i] + mid)
			return false;
		else if(b[i-1] < a[i] && (a[i] + mid < m || (a[i] + mid) % m < b[i-1]))
			b[i] = a[i];
		else
			b[i] = b[i-1];
	}
	return true;
}
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l = -1, r = m;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(Solve(mid, n, m)) r = mid;
		else l = mid;
	}
	printf("%d\n", r);
	return 0;
}