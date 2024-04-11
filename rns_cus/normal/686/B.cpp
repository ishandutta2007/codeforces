#include <bits/stdc++.h>
using namespace std;
int n,a[111];
main(){
	scanf("%d",&n);
	for(int i = 1;i <=n;i++)scanf("%d", a +i);
	for(int i = 1; i <= n; i ++) {
		int mn = 2e9,id;
		for(int j = i; j <= n; j ++) if(mn>a[j])mn=a[j],id=j;
		for(int j = id; j > i; j --) {
			printf("%d %d\n", j - 1, j);
			swap(a[j-1], a[j]);
		}
	}
}