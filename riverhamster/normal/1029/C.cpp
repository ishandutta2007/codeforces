#include <cstdio>

int l[300005], r[300005];

inline int max(int a, int b){
	return a>b?a:b; 
}

int main(){
	int n, maxl = -1, max2l = -1, minr = 0x7fffffff, min2r = 0x7fffffff;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d%d", &l[i], &r[i]);
		if(l[i] > maxl){
			max2l = maxl;
			maxl = l[i];
		} 
		else if(l[i] > max2l) max2l = l[i];
		if(r[i] < minr){
			min2r = minr;
			minr = r[i];
		}
		else if(r[i] < min2r) min2r = r[i];
	}
	int ans = max(minr - maxl, 0);
//	printf("minr = %d maxl = %d\n", minr, maxl);
	for(int i=1; i<=n; i++){
		if(l[i] == maxl) ans = max(ans, minr - max2l);
		if(r[i] == minr) ans = max(ans, min2r - maxl);
		if(l[i] == maxl && r[i] == minr) ans = max(ans, min2r - max2l);
	}
	printf("%d\n", ans);
	return 0;
}