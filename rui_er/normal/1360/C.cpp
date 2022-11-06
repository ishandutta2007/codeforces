//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[51];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int odd = 0, even = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			if(a[i] & 1) {
				++odd;
			}
			else {
				++even;
			}
		}
		sort(a+1, a+1+n);
		bool book = false;
		for(int i=2;i<=n;i++) {
			if(a[i] - a[i-1] == 1) {
				book = true;
				break;
			}
		}
		if(book) {
			puts("YES");
		}
		else if(even % 2 == 0 && odd % 2 == 0) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}