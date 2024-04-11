#include <cstdio>
struct Segment{
	int left,right;
}a[1005];
int main(){
	int n,r;
	int len=0;
	int now;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&now);
		if(now==1){
			a[++len].left=i-r+1;
			if(a[len].left<1){
				a[len].left=1;
			}
			a[len].right=i+r-1;
			if(a[len].right>n){
				a[len].right=n;
			}
		}
	}
	int last_right=0;
	int ans=0;
	int tmp;
	while(last_right<n){
		tmp=-1;
		for(int i=1;i<=len;i++){
			if(a[i].left<=last_right+1){
				tmp=i;
			}
		}
		ans++;
		if(a[tmp].right<=last_right){
			ans=-1;
			break;
		}
		last_right=a[tmp].right;
		if(tmp==-1){
			ans=-1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}