#include <bits/stdc++.h>
using namespace std;

#define N 333

int a[N][N], b[N][N];

int main() {
	int t;
	cin >> t;
	while(t --) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) cin >> a[i][j];
		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
			b[i][j] = 0;
            if(1 < i) b[i][j] ++;
            if(i < n) b[i][j] ++;
            if(1 < j) b[i][j] ++;
            if(j < m) b[i][j] ++;
		}
		bool ans = 1;
		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(a[i][j] > b[i][j]) {
			ans = 0;
			break;
		}
        if(ans) {
			puts("YES");
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= m; j ++) printf("%d ", b[i][j]);
				puts("");
			}
        }
        else puts("NO");
	}
}