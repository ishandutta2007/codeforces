//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		if(n <= 30) {
			puts("NO");
			continue;
		}
		if(n == 36) {
			puts("YES");
			puts("5 6 10 15");
			continue;
		}
		if(n == 40) {
			puts("YES");
			puts("6 10 22 2");
			continue;
		}
		if(n == 44) {
			puts("YES");
			puts("6 7 10 21");
			continue;
		}
		puts("YES");
		printf("6 10 14 %d\n", n-30);
	}
	return 0;
}