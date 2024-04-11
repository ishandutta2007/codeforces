//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, a, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &a, &b);
		int mi = min(a, b);
		int ma = max(a, b);
		int k = max(ma, 2*mi);
		printf("%d\n", k*k);
	} 
	return 0;
}