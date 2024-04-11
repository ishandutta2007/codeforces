#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=200005,M=10000005;
char s[N],T[N];
int n,m,lst,tot,lth,x,root[N<<1],p[N<<1];
int fa[N<<1],trf[N<<1][30],len[N<<1];
int seg_tot,rk[N<<1],bin[N],c[N<<1];
int ans[N],tmp[N],t[M],ls[M],rs[M];
struct data{int id,len,x;};
vector <data> vt[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void add(int c)
{
	int u=lst,x=++tot,v;
	len[x]=len[u]+1,lst=tot;
	for(; u && !trf[u][c]; trf[u][c]=x,u=fa[u]);
	if(!u) fa[x]=1;
	else if(len[u]+1==len[v=trf[u][c]]) fa[x]=v;
	else
	{
		int w=++tot;
		len[w]=len[u]+1,memcpy(trf[w],trf[v],sizeof(trf[v]));
		fa[w]=fa[v];
		for(fa[v]=fa[x]=w; u && trf[u][c]==v; trf[u][c]=w,u=fa[u]);
	}
}

void ins(int l,int r,int &rt,int x)
{
	if(!rt) rt=++seg_tot;
	if(l==r)
	{
		t[rt]=1;
		return;
	}
	if(x<=mid) ins(l,mid,ls[rt],x);
	else ins(mid+1,r,rs[rt],x);
}

void merge(int l,int r,int lst,int &rt)
{
	if(!lst) return;
	if(!rt)
	{
		rt=lst;
		return;
	}
	merge(l,mid,ls[lst],ls[rt]);
	merge(mid+1,r,rs[lst],rs[rt]);
}

void rever(int l,int r,int rt)
{
	if(!rt) return;
	if(l==r) {tmp[++*tmp]=l; return;}
	rever(l,mid,ls[rt]),rever(mid+1,r,rs[rt]);
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1),lst=tot=1;
	rep(i,1,n) add(s[i]-'a'),p[lst]=i,c[lst]=1;
	rep(i,1,tot) ++bin[len[i]];
	rep(i,1,n) bin[i]+=bin[i-1];
	rep(i,1,tot) rk[bin[len[i]]--]=i;

	repd(i,tot,1) c[fa[rk[i]]]+=c[rk[i]];

	m=getint();
	rep(i,1,m)
	{
		x=getint(),scanf("%s",T+1),lth=strlen(T+1);
		int nw=1;
		rep(j,1,lth) nw=trf[nw][T[j]-'a'];
		if(nw && x<=c[nw]) vt[nw].push_back((data){i,lth,x});
		else ans[i]=-1;
	}
	repd(i,tot,1)
	{
		int x=rk[i];
		if(p[x]) ins(1,n,root[x],p[x]);
		int siz=vt[x].size();
		if(siz)
		{
			*tmp=0,rever(1,n,root[x]);
			rep(j,0,siz-1)
			{
				ans[vt[x][j].id]=n;
				rep(k,vt[x][j].x,*tmp)
					ans[vt[x][j].id]=min(ans[vt[x][j].id],tmp[k]-tmp[k-vt[x][j].x+1]+vt[x][j].len);
			}
		}
		merge(1,n,root[x],root[fa[x]]);
	}
	rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}