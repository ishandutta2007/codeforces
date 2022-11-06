//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[105], p[105], a1, a2; 

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(p, 0, sizeof(p));
		a1 = a2 = 0;
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			++p[a[i]];
		}
		for(int i=0;i<=100;i++) {
			if(!p[i]) break;
			if(p[i] == 1) {
				if(a1 == i) a1 = i + 1;
				else if(a2 == i) a2 = i + 1;
			}
			else {
				if(a1 == i) a1 = i + 1;
				if(a2 == i) a2 = i + 1;
			}
		}
		printf("%d\n", a1+a2);
	}
	return 0;
}