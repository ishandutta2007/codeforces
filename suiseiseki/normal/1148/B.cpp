#include <cstdio>
#define Maxn 200000
int a[Maxn+5];
int b[Maxn+5];
int n,m,ta,tb,k;
int find(int x){
	int left=1,right=m+1;
	int mid;
	while(left<right){
		mid=(left+right)>>1;
		if(x>b[mid]){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return left;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	b[m+1]=2000000001;
	if(k>=n||k>=m){
		puts("-1");
		return 0;
	}
	int x;
	int ans=0;
	for(int i=1;i<=k+1;i++){
		x=find(a[i]+ta);
		x+=k-i+1;
		if(x>m){
			puts("-1");
			return 0;
		}
		ans=mx(ans,b[x]+tb);
	}
	printf("%d\n",ans);
	return 0;
}