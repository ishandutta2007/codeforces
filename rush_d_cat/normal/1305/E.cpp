#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,ans[10000];
LL cac(int x){
	int v = x-2;
	int ans=0;
	while(v>=0) {
		ans+=v; v-=2;
	}
	return ans;
}
int main() {
	//printf("cac %d\n", cac(7));
	cin>>n>>m;
	if(n==1) {
		if(m>=1) printf("-1\n");
		else printf("1\n");
		return 0;
	}
	int x=n;
	while(x>=1 && cac(x-1)>=m) {
		--x;
	}
	if(cac(x)<m) return !printf("-1\n");
	int dt = cac(x) - m;
	//printf("dt=%d\n", dt);
	for(int i=1;i<x;i++) ans[i]=i;
	ans[x]=x+dt*2;
	int B=1000000000;
	for(int i=n;i>x;i--){
		ans[i]=B; B-=100000;
	}
	for(int i=1;i<=n;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
/*
	int c=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(ans[i]+ans[j]==ans[k]) c++;
			}
		}
	}
	printf("%d\n", c);
*/
}