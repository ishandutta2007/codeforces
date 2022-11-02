#include <stdio.h>
const int maxn = 100100;
int a[maxn];
int main(){
	int n, m, l, c = 0;
	scanf("%d%d%d", &n, &m, &l);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		if(a[i] > l && a[i-1] <= l) c++;
	for(int i = 1; i <= m; i++){
		int ty; scanf("%d", &ty);
		if(!ty) printf("%d\n", c);
		else{
			int p, d; 
			scanf("%d%d", &p, &d);
			if(a[p] > l);
			else{
				a[p] += d;
				if(a[p] <= l);
				else if(a[p-1] > l && a[p+1] > l) c--;
				else if(a[p-1] <= l && a[p+1] <= l) c++;
			}
		}
	}
	return 0;
}