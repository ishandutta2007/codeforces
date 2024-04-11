#include <cstdio>
int h[15];
int an[15];
int y[15];
int n,a,b;
int ans=(1<<30);
void dfs(int x,int now){
	if(now>=ans){
		return;
	}
	if(x==n){
		if(h[x]<0){
			ans=now;
			for(int i=1;i<=n;i++){
				an[i]=y[i];
			}
		}
		return;
	}
	if(h[x-1]<0){
		dfs(x+1,now);
	}
	int tmp=0;
	for(int i=1;h[x-1]>=0||h[x]>=0||h[x+1]>=0;i++){
		tmp++;
		h[x-1]-=b;
		h[x]-=a;
		h[x+1]-=b;
		y[x]=tmp;
		if(h[x-1]<0){
			dfs(x+1,now+tmp);
		}
	}
	y[x]=0;
	h[x-1]+=b*tmp;
	h[x]+=a*tmp;
	h[x+1]+=b*tmp;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	dfs(2,0);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		while(an[i]--){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}