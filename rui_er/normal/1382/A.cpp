//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int a, b, bucket[1005]; 

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(bucket, 0, sizeof(bucket));
		bool book = true;
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a);
			bucket[a] = 1;
		}
		for(int i=1;i<=m;i++) {
			scanf("%d", &b);
			if(bucket[b] && book) {
				puts("YES");
				printf("1 %d\n", b);
				book = false;
			}
		}
		if(book) {
			puts("NO");
		}
	}
	return 0;
}