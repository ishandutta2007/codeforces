#include <cstdio>
struct Segment{
	int left,right;
}a[200005];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].left,&a[i].right);
	}
	int start=a[1].left,x=1,y,now=h;
	for(int i=1;i<n;i++){
		now-=a[i+1].left-a[i].right;
		if(now>0){
			y=i+1;
		}
		else{
			break;
		}
	}
	if(h==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=mx(ans,a[i].right-a[i].left+1);
		}
		printf("%d\n",ans);
	}
	else{
		if(now>0){
			printf("%d\n",a[n].right-start+now);
		}
		else{
			now+=a[y+1].left-a[y].right;
			int ans=a[y].right-start+now;
			while(x<n){
				x++;
				now+=a[x].left-a[x-1].right;
				while(now>a[y+1].left-a[y].right&&y<n){
					now-=a[y+1].left-a[y].right;
					y++;
				}
				ans=mx(ans,a[y].right-a[x].left+now);
				if(y==n){
					break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}