#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,a[200500];
ll l[200500],r[200500],res,xx,yy;

int dis(int x,int y){
	return abs(x-y)+abs(a[x]-a[y]);
}

bool chk(int l,int r){
	int i,j,k;
	for(i=l;i<=r;i++){
		for(j=l;j<=r;j++){
			for(k=l;k<=r;k++){
				if(i==j||i==k||j==k){continue;}
				if(dis(i,j)+dis(j,k)==dis(i,k)){return 0;}
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=n;
		res+=n-1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i+2<=n;i++){
			res+=chk(i,i+2);
		}
		
		for(i=1;i+3<=n;i++){
			res+=chk(i,i+3);
		}
		
		printf("%lld\n",res);
	}
}