#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 2010;
int s[maxn], t[maxn], f[maxn * maxn];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		s[i] += s[i-1];
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &t[i]);
		t[i] += t[i-1];
	}
	int x;
	scanf("%d", &x);
	for(int l = 0; l <= m; l++)
		for(int r = l + 1; r <= m; r++)
			f[t[r] - t[l]] = max(f[t[r] - t[l]], r - l); 
	for(int i = 1; i <= 4000000; i++)
		f[i] = max(f[i-1], f[i]);
	int ans = 0;
	for(int l = 0; l <= n; l++)
		for(int r = l + 1; r <= n; r++)
			ans = max(ans, (r - l) * f[min(4000000, x / (s[r] - s[l]))]);
	printf("%d\n", ans);
	return 0;
}