#include <cstdio>
#include <iostream>
using namespace std;
const int N = 40001;

int n, m, k, a[N], b[N];
long long ans;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i), a[i] += a[i - 1];
	for(int i = 1; i <= m; i++)
		scanf("%d", b + i), b[i] += b[i - 1];
	for(int l = (k - 1) / m + 1, end = min(k, n); l <= end; l++) if(k % l == 0){
		int cnt = 0, r = k / l;
		for(int i = 0; i + l <= n; i++)
			if(a[i + l] - a[i] == l) cnt++;
		for(int i = 0; i + r <= m; i++)
			if(b[i + r] - b[i] == r) ans += cnt;
	}
	printf("%lld", ans);
	return 0;
}