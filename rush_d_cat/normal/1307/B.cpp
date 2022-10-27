#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1000000 + 10;
int t,n,x,a[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		int ans=1e9;
		bool fg=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); if(a[i]==x) fg=1;
			ans=min(ans,(x+a[i]-1)/a[i]);
		}
		if(ans==1 && fg==0) ans=2;
		printf("%d\n", ans);
	}
}