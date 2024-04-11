#include<cstdio>
using namespace std;
const int o=1e6;
int n,x[o],y[o],h[o],cnt=1,st[o],tp,ans[2][o];bool vis[o],usd[o];char a[2][o],b[2][o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	st[++tp]=nw;
	if(vis[nw]) return;
	vis[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(!usd[i/2]) usd[i/2]=1,dfs(e[i].v),st[++tp]=nw;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]),ad(x[i],y[i]),ad(y[i],x[i]);
	cnt=0;
	for(int i=1;i<=2*n;++i) if(!vis[i]){
		tp=0;dfs(i);
		if(tp==3){printf("-1");return 0;}
		if((--tp)/2%2){
			a[0][cnt+1]=b[0][cnt+tp/2]='U';a[1][cnt+1]=b[1][cnt+tp/2]='D';
			for(int j=2;j<tp/2;j+=2) a[0][j+cnt]=a[1][j+cnt]='L',a[0][j+cnt+1]=a[1][j+cnt+1]='R';
			for(int j=1;j<tp/2;j+=2) b[0][j+cnt]=b[1][j+cnt]='L',b[0][j+cnt+1]=b[1][j+cnt+1]='R';
		}
		else{
			b[0][cnt+1]=b[0][cnt+tp/2]='U';b[1][cnt+1]=b[1][cnt+tp/2]='D';
			for(int j=1;j<tp/2;j+=2) a[0][j+cnt]=a[1][j+cnt]='L',a[0][j+cnt+1]=a[1][j+cnt+1]='R';
			for(int j=2;j<tp/2;j+=2) b[0][j+cnt]=b[1][j+cnt]='L',b[0][j+cnt+1]=b[1][j+cnt+1]='R';
		}
		for(int j=1,k=tp;j<k;) ans[0][++cnt]=st[j++],ans[1][cnt]=st[k--];
	}
	printf("2 %d\n\n",n);
	for(int i=1;i<=n;++i) printf("%d ",ans[0][i]);
	putchar('\n');
	for(int i=1;i<=n;++i) printf("%d ",ans[1][i]);
	printf("\n\n");
	for(int i=1;i<=n;++i) putchar(a[0][i]);
	putchar('\n');
	for(int i=1;i<=n;++i) putchar(a[1][i]);
	printf("\n\n");
	for(int i=1;i<=n;++i) putchar(b[0][i]);
	putchar('\n');
	for(int i=1;i<=n;++i) putchar(b[1][i]);
	return 0;
}