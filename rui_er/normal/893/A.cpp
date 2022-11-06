//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, a, sp;

int main() {
	scanf("%d", &n);
	sp = 3;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a);
		if(a == sp) return puts("NO"), 0;
		if(sp == 1) sp = 5 - a;
		else if(sp == 2) sp = 4 - a;
		else sp = 3 - a;
	}
	puts("YES");
	return 0;
}