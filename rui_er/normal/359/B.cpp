// LUOGU_RID: 90441040
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		int x = (i << 1) - 1;
		int y = i << 1;
		if(i <= k) printf("%d %d ", y, x);
		else printf("%d %d ", x, y);
	}
	return 0;
}