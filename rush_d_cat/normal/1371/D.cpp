#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 304;

int t, n, k;
int a[N][N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &k);
		if (k%n == 0) printf("0\n");
		else printf("2\n");
		for (int i = 0; i <= n; i ++) for (int j = 0; j <= n; j ++) a[i][j] = 0;
		if(k){
			for (int d = 0; d < n; d ++) {
				if(k==0) break;
				for (int i = 0; i < n; i ++) {
					if(k==0) break;
					a[i][(i+d)%n] = 1; k--;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)printf("%d", a[i][j]);
			printf("\n");
		}
	}
}