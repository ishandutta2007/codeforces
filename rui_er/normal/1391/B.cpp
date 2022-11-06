//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int a[105][105];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(a, 0, sizeof(a));
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				char c = getchar();
				while(c != 'D' && c != 'R' && c != 'C') c = getchar();
				if(c == 'D') a[i][j] = 1;
				else if(c == 'R') a[i][j] = 2;
				else a[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i=1;i<n;i++) {
			if(a[i][m] == 2) ++ans;
		} 
		for(int i=1;i<m;i++) {
			if(a[n][i] == 1) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}