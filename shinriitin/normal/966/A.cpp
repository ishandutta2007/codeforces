#include <bits/stdc++.h>

#define inf (0x3f3f3f3f)

const int max_N = (int)1e5 + 21;

int n, m, q, v, na, nb, a[max_N], b[max_N];

int findMin(int* a, int n, int l, int r){
	if(!n) return inf;
	int pos_l = std::lower_bound(a+1, a+1+n, l) - a;
	int pos_r = std::lower_bound(a+1, a+1+n, r) - a;
	if(pos_l<=n&&a[pos_l]<=r) return r-l;
	int res = inf;
	if(pos_l>1) res = std::min(res, (r-l) + 2*(l-a[pos_l-1]));
	if(pos_r<=n) res = std::min(res, (r-l) + 2*(a[pos_r]-r));
	return res;
}

int main(){
	scanf("%d%d%d%d%d", &n, &m, &na, &nb, &v);
	for(int i=1;i<=na;++i) scanf("%d", a+i);
	for(int i=1;i<=nb;++i) scanf("%d", b+i);
	scanf("%d", &q);
	while(q --){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) std::swap(x1, x2);
		if(y1 > y2) std::swap(y1, y2);
		if(x1 == x2){
			printf("%d\n", y2 - y1);
			continue;
		}
		int tmp1 = findMin(a, na, y1, y2) + x2 - x1;
		int tmp2 = findMin(b, nb, y1, y2) + (x2-x1+v-1)/v;
		printf("%d\n", std::min(tmp1, tmp2));
	}
	return 0;
}