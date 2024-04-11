//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, q;
int a[N], cnt2, cnt4, cnt6, cnt8;

char read() {
	char c = getchar();
	while(c != '+' && c != '-') c = getchar();
	return c;
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int k;
		scanf("%d", &k);
		++a[k];
		if(a[k] == 8) --cnt6, ++cnt8;
		else if(a[k] == 6) --cnt4, ++cnt6;
		else if(a[k] == 4) --cnt2, ++cnt4;
		else if(a[k] == 2) ++cnt2;
//		printf("%d %d %d %d\n", cnt8, cnt6, cnt4, cnt2);
	}
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		char c = read();
		int k;
		scanf("%d", &k);
		int _ = a[k];
//		printf("GET: %c %d\n", c, k);
		if(c == '+') ++a[k];
		else --a[k];
		if(_ >= 8) {
			if(a[k] < 8) --cnt8, ++cnt6;
		}
		else if(_ >= 6) {
			if(a[k] >= 8) --cnt6, ++cnt8;
			if(a[k] < 6) --cnt6, ++cnt4;
		}
		else if(_ >= 4) {
			if(a[k] >= 6) --cnt4, ++cnt6;
			if(a[k] < 4) --cnt4, ++cnt2;
		}
		else if(_ >= 2) {
			if(a[k] >= 4) --cnt2, ++cnt4;
			if(a[k] < 2) --cnt2;
		}
		else if(a[k] >= 2) ++cnt2;
//		printf("%d %d %d %d\n", cnt8, cnt6, cnt4, cnt2);
		if(cnt8 || (cnt6 >= 2) || (cnt6 && (cnt4 || cnt2)) || (cnt4 >= 2)
			|| (cnt4 && cnt2 >= 2)) {
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}