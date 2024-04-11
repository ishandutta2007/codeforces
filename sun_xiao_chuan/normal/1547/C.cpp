#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,l,r,a[1050],b[1050],res[1050],it;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&k,&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);
		}
		it=0;
		l=r=1;
		a[n+1]=b[m+1]=114514;
		while(it!=(n+m)){
			if(a[l]<=k){
				res[++it]=a[l];
				if(!a[l]){k++;}l++;
				continue;
			}
			if(b[r]<=k){
				res[++it]=b[r];
				if(!b[r]){k++;}r++;
				continue;
			}
			puts("-1");goto aaa;
		}
		for(i=1;i<=n+m;i++){
			printf("%d ",res[i]);
		}puts("");
		aaa:;
	}
}