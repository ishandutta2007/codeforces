//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[55][55];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				char c = getchar();
				while(!isdigit(c)) c = getchar();
				a[i][j] = c - '0';
			}
		}
		bool book = true;
		for(int i=1;i<n;i++) {
			for(int j=1;j<n;j++) {
				if(a[i][j] && !a[i][j+1] && !a[i+1][j]) {
					book = false;
					break;
				}
			}
			if(!book) break;
		}
		if(book) puts("YES");
		else puts("NO");
	}
	return 0;
}