#include<bits/stdc++.h>
const int N=300005;
using namespace std;
char ch;
inline void rd(int&x){
	for(;!isdigit(ch=getchar()););
	for(x=ch-48;isdigit(ch=getchar());
	x=(x<<3)+(x<<1)+ch-48);
}
int n,m,to[N*2],hd[N*2],lk[N],cnt,
f[N],sz[N],son[N],top[N],dep[N],dfn[N],
tu[N],td[N],ta,tb,ans,nt,tp;
struct seg{
	int x,l,d;
}sa[N],sb[N],tmp[N];
namespace SAM{
	int p,q,r,s,c[N*4][26],ln[N*4],f[N*4],cnt=1,
	dfn[N*8],st[23][N*8],hd[N*4],lk[N*4],lg[N*8];
	inline void extend(int tr,int d){
		c[p][tr]?s=0:ln[s=++cnt]=d;
		for(;p&&!c[p][tr];p=f[p])c[p][tr]=s;
		if(q=c[p][tr]){
			if(ln[q]==ln[p]+1)
			s?f[s]=q:s=q;
			else{
				ln[r=++cnt]=ln[p]+1,f[r]=f[q];
				f[q]=r;s?f[s]=r:s=r;
				for(int i=0;i<26;i++)
				c[r][i]=c[q][i];
				for(;c[p][tr]==q;p=f[p])
				c[p][tr]=r;
			}
		}else f[s]=1;
		p=s;
	}
	void dfs(int x){
		st[0][dfn[x]=++cnt]=ln[x];
		for(int i=lk[x];i;i=hd[i])
		dfs(i),st[0][++cnt]=ln[x];
	}
	inline void prec(){
		for(int i=2;i<=cnt;i++)
		hd[i]=lk[f[i]],lk[f[i]]=i;
		cnt=0,dfs(1);
		for(int i=0;1<<i<cnt;lg[1<<i]++,i++)
		for(int j=1;j+(1<<i)<=cnt;j++)
		st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
		lg[1]=0;
		for(int i=2;i<=cnt;i++)lg[i]+=lg[i-1];
	}
	int lca(int x,int y){
		if(dfn[x]>dfn[y])swap(x,y);
		int d=lg[dfn[y]-dfn[x]];
		return min(st[d][dfn[x]],st[d][dfn[y]-(1<<d)+1]);
	}
}
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
char a[N];
void dfs(int x){
	sz[x]=1,dep[x]=dep[f[x]]+1;
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^f[x])
	f[s]=x,dfs(s),sz[x]+=sz[s],
	sz[son[x]]<sz[s]?son[x]=s:0;
}
void cal(int x,int d){
	dfn[x]=++nt;
	SAM::extend(a[x]-'a',d),tu[nt]=SAM::p;
	if(top[x]==x)SAM::p=1;
	else cal(f[x],d+1);
	SAM::extend(a[x]-'a',dep[x]-dep[top[x]]+1);
	td[dfn[x]]=SAM::p;
}
void dfss(int x){
	!top[x]?top[x]=x:0;
	if(son[x])top[son[x]]=top[x];
	else SAM::p=1,cal(x,1);
	for(int s,i=lk[x];i;i=hd[i])
	if(f[s=to[i]]==x)dfss(s);
}
int u,v;
inline void sep(seg*s,int&t){
	nt=t=0;
	for(;top[u]^top[v];)
	if(dep[top[u]]<dep[tp=top[v]])
	tmp[nt++]={dfn[tp],dep[v]-dep[tp]+1,-1},v=f[tp];
	else tp=top[u],
	s[t++]={dfn[u],dep[u]-dep[tp]+1,1},u=f[tp];
	s[t++]=dep[u]<dep[v]?(seg){dfn[u],dep[v]-dep[u]+1,-1}:
	(seg){dfn[u],dep[u]-dep[v]+1,1};
	for(;nt--;)s[t++]=tmp[nt];
}
inline void cal(seg&a,seg&b){
	int d=min(min(a.l,b.l),
	SAM::lca(a.d>0?td[a.x]:tu[a.x],b.d>0?td[b.x]:tu[b.x]));
	a.x+=a.d*d,b.x+=b.d*d;
	a.l-=d,b.l-=d,ans+=d;
}
int main(){
	scanf("%d%s",&n,a+1);
	for(int i=1;i<n;i++)
	rd(u),rd(v),add(u,v),add(v,u);
	cnt=0,dfs(1),dfss(1);
	SAM::prec();
	for(rd(m);m--;){
		ans=0;
		rd(u),rd(v),sep(sa,ta);
		rd(u),rd(v),sep(sb,tb);
		for(int i=0,j=0;i<ta&&j<tb;){
			cal(sa[i],sb[j]);
			if(sa[i].l&&sb[j].l)break;
			i+=!sa[i].l,j+=!sb[j].l;
		}
		printf("%d\n",ans);
	}
}