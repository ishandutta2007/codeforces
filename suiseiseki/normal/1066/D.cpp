#include <cstdio>
int n,m,k;
int a[200005];
bool check(int x){
	int use=1;
	int now=0;
	for(int i=x+1;i<=n;i++){
		if(now+a[i]>k){
			use++;
			now=a[i];
		}
		else{
			now+=a[i];
		}
	}
	return use<=m;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int left=0,right=n,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",n-left);
	return 0;
}