#include <cstdio>
#include <algorithm>
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int left=n+n-1,right=n*2000+n-1;
	while(left<right){
		int mid=(left+right)/2;
		if(query(mid)==1){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	int ans=left;
	for(int i=2;i<=n;i++){
		int val=left/i;
		if(val*i==left){
			val--;
		}
		if(query(val)==i){
			ans=std::min(ans,val*i);
		}
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}