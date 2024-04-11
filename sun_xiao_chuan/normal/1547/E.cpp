#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[300500],res[300500],sb,b[300500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(res,0x6f,n*4+50);
		sb=res[0];
		memset(a,0x6f,n*4+50);
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			a[b[i]]=k;
		}
		for(i=1;i<=n;i++){
			sb=min(sb+1,a[i]);
			res[i]=min(res[i],sb);
		}
		sb=res[0];
		for(i=n;i>=1;i--){
			sb=min(sb+1,a[i]);
			res[i]=min(res[i],sb);
		}
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}
		puts("");
	}
}