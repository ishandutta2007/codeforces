#include <cstdio>
#include <iostream>
using namespace std;
const int N = 250;

int t, n, c[2 * N][2 * N];
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0x7fffffffffffffff;
		scanf("%d", &n);
		for(int i = 0; i < 2 * n; i++)
			for(int j = 0; j < 2 * n; j++)
				scanf("%d", &c[i][j]);
		ans = min(min(min(c[0][n], c[0][2 * n - 1]), min(c[n - 1][n], c[n - 1][2 * n - 1])), min(min(c[n][0], c[n][n - 1]), min(c[2 * n - 1][0], c[2 * n - 1][n - 1])));
		for(int i = n; i < 2 * n; i++)
			for(int j = n; j < 2 * n; j++)
				ans += c[i][j];
		printf("%lld\n", ans);
	}
	return 0;
}