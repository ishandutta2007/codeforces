#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1001;

int n, c[N];
long long f[N][N], ans;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", c + i);
		f[i][0] = f[i - 1][0] + ((i & 1) ? c[i] : -c[i]);
	}
	n = n & ~1;
	for(int l = 1; l < n; l++)
		for(int i = 1; i + l <= n; i++){
			f[i][l] = min(f[i + 1][l - 1], f[i][0]);
		}
	for(int i = 1; i < n; i += 2)
		ans += min(c[i], c[i + 1]);
	for(int l = 3; l < n; l += 2)
		for(int i = 1; i + l <= n; i += 2){
			long long cnt = f[i + l - 1][0] - f[i][0];
			if(cnt > 0) ans += max(0ll, min(c[i + l] - cnt, 1ll * c[i]) - max(f[i + l][0] - f[i + 1][l - 2] - cnt, f[i][0] - f[i + 1][l - 2]) + 1);
			else ans += max(0ll, min(1ll * c[i + l], c[i] + cnt) - max(f[i + l][0] - f[i + 1][l - 2], cnt + f[i][0] - f[i + 1][l - 2]) + 1);
		}
	printf("%lld", ans);
	return 0;
}