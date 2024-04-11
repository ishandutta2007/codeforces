//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[100005];

int main() {
	scanf("%d", &T);
	while(T--) {
		bool book = true;
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			if(a[i] > 1 && book) {
				if(i&1) {
					puts("First");
				}
				else {
					puts("Second");
				}
				book = false;
			}
		}
		if(book) {
			if(n&1) {
				puts("First");
			}
			else {
				puts("Second");
			}
		}
	}
	return 0;
}