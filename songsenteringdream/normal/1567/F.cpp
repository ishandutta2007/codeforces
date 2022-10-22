#include<cstdio>
using namespace std;
const int o=1010;
int n,m,col[o][o],tot,cnt,h[o*o],res[o*o],ans[o][o];char s[o][o];
struct Edge{int v,p;}e[o*o*4];
inline void ad(int U,int V){if(U^V) e[++cnt].v=V,e[cnt].p=h[U],h[U]=cnt;}
void pnt(int x,int y){
	for(int i=-1,tx,ty;i<2;++i) for(int j=-1;j<2;++j) if((tx=x+i)&&(ty=y+j))
		if(tx<=n&&ty<=m&&s[tx][ty]=='.'&&!col[tx][ty]) col[tx][ty]=tot,pnt(tx,ty);
}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p)
		if(!res[e[i].v]) res[e[i].v]=3-res[nw],dfs(e[i].v);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=2;i<n;++i) for(int j=2;j<m;++j) if(s[i][j]=='X')
		if(((s[i-1][j]=='.')+(s[i+1][j]=='.')+(s[i][j-1]=='.')+(s[i][j+1]=='.'))%2)
			{printf("NO");return 0;}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		if(s[i][j]=='.'&&!col[i][j]) col[i][j]=++tot,pnt(i,j);
	for(int i=2;i<n;++i) for(int j=2;j<m;++j) if(s[i][j]=='X'){
		if(s[i-1][j]=='.'&&s[i+1][j]=='.') ad(col[i-1][j],col[i+1][j]),ad(col[i+1][j],col[i-1][j]);
		if(s[i][j-1]=='.'&&s[i][j+1]=='.') ad(col[i][j-1],col[i][j+1]),ad(col[i][j+1],col[i][j-1]);
	}
	for(int i=1;i<=tot;++i) if(!res[i]) res[i]=1,dfs(i);
	for(int i=1;i<=m;++i)
		for(int cur=ans[1][i]=1+3*(i&1),lst=res[col[1][i]],j=2;j<=n;++j)
			if(s[j][i]=='.'){
				if(res[col[j][i]]^lst) cur=5-cur;
				ans[j][i]=cur;lst=res[col[j][i]];
			}
	for(int i=2;i<n;++i) for(int j=2;j<m;++j) if(s[i][j]=='X')
		ans[i][j]=(s[i-1][j]=='.')*ans[i-1][j]+(s[i+1][j]=='.')*ans[i+1][j]
		+(s[i][j-1]=='.')*ans[i][j-1]+(s[i][j+1]=='.')*ans[i][j+1];
	printf("YES\n");
	for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=m;++j) printf("%d ",ans[i][j]);
	return 0;
}