#include <cstdio>
#define Maxn 2000
#define ll long long
struct Node{
	int x,y;
}a[Maxn+5];
char s[Maxn+5];
bool vis[Maxn+5];
int n;
int ans[Maxn+5];
ll cross(ll x_1,ll y_1,ll x_2,ll y_2){
	return 1ll*x_1*y_2-1ll*x_2*y_1;
}
ll cross(int i,int j,int k){
	return cross(a[j].x-a[i].x,a[j].y-a[i].y,a[k].x-a[i].x,a[k].y-a[i].y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(ans[1]==0||a[i].x<a[ans[1]].x){
			ans[1]=i;
		}
	}
	scanf("%s",s+1);
	vis[ans[1]]=1;
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(ans[i+1]==0||(s[i]=='L'&&cross(ans[i],j,ans[i+1])>0)||(s[i]=='R'&&cross(ans[i],j,ans[i+1])<0)){
				ans[i+1]=j;
			}
		}
		vis[ans[i+1]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans[n]=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}