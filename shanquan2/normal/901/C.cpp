#include<bits/stdc++.h>
using namespace std;

const int N=300100;
struct edge{
	int nxt,to;
}e[N<<1];
struct fe{
	int l,r;
	bool operator <(const fe &o)const{return r<o.r;}
}b[N];
int ft[N],q[N],dfn[N],top,cnt,n,m,num,a[N];
long long s[N];
bool vis[N];
void dfs(int x,int fa){
	q[top++]=x;vis[x]=1;dfn[x]=num++;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa){
		int y=e[i].to;
		if(!vis[y])dfs(y,x);
		else if(dfn[y]<dfn[x]){
			int mn=y,mx=y;
			for(int j=top-1;q[j]!=y;j--){
				if(mn>q[j])mn=q[j];
				if(mx<q[j])mx=q[j];
			}
			b[cnt++]=(fe){mn,mx};
		}
	}
	top--;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[i<<1]=(edge){ft[x],y};ft[x]=i<<1;
		e[i<<1|1]=(edge){ft[y],x};ft[y]=i<<1|1;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i,0);
//	for(int i=0;i<cnt;i++)printf("%d %d\n",b[i].l,b[i].r);
	sort(b,b+cnt);
	int now=0;
	for(int i=1,j=0;i<=n;i++){
		while(j<cnt&&i>=b[j].r)now=max(now,b[j].l),j++;
		a[i]=now;
	}
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	for(int i=1;i<=n;i++)s[i]=s[i-1]+i-a[i];
	int q;scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		long long ans=0;
		int u=lower_bound(a+l,a+r+1,l)-a;
		ans=1ll*(u-l)*(u-l+1)/2+s[r]-s[u-1];
		printf("%I64d\n",ans);
	}
	return 0;
}