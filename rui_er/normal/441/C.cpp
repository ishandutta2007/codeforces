// LUOGU_RID: 90440911
//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> calcPos(int x) {
	int div = (x - 1) / n + 1, pos = (x - 1) % n + 1;
	if(div & 1) return make_pair(div, pos);
	return make_pair(div, n-pos+1);
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i=1;i<k;i++) {
		printf("2 ");
		pair<int, int> _;
		_ = calcPos((i<<1)-1);
		printf("%d %d ", _.first, _.second);
		_ = calcPos(i<<1);
		printf("%d %d\n", _.first, _.second);
	}
	printf("%d ", n*m-((k-1)<<1));
	for(int i=(k<<1)-1;i<=n*m;i++) {
		pair<int, int> _;
		_ = calcPos(i);
		printf("%d %d ", _.first, _.second);
	}
	puts("");
	return 0;
}