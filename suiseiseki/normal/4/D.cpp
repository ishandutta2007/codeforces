#include <cstdio>
#include <cstring>
struct Card{
	int x,y;
	friend bool operator <(Card p,Card q){
		return p.x<q.x&&p.y<q.y;
	}
}a[5005];
int f[5005];
int nxt[5005];
int n;
int dfs(int s){
	if(f[s]!=-1){
		return f[s];
	}
	int ans=0,now;
	for(int i=1;i<=n;i++){
		if(a[s]<a[i]){
			now=dfs(i);
			if(now>ans){
				nxt[s]=i;
				ans=now;
			}
		}
	}
	return f[s]=ans+1;
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&a[0].x,&a[0].y);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	printf("%d\n",dfs(0)-1);
	for(int i=nxt[0];i;i=nxt[i]){
		printf("%d ",i);
	}
	puts("");
	return 0;
}