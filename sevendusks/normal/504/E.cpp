/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define p1 342914237
#define base 5274747
#define len(a) (int)a.size()
using namespace std;
const int N=3*1e5+100;
int n,sz[N],fa[N],son[N],tp[N],dfn[N],tr[N],cnt,de[N];
vector <int> e[N];
char s[N],ch[N*2];
struct node
{
	int l,r;
}A[210];
node B[210];
inline void add(int &a,int b,int mod){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b,int mod){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b,int mod){a=1ll*a*b%mod;}
inline int m_pow(int a,int b,int mod)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a,mod);
		b>>=1;
		mul(a,a,mod);
	}
	return ans;
}
inline char gc()
{
	static char now[1<<20],*s,*t;
	if (s==t)
	{
		t=(s=now)+fread(now,1,1<<20,stdin);
		if (s==t) return EOF;
	}
	return *s++;
}
inline int read()
{
	int f=1,x=0;char s=gc();
	while(!isdigit(s)){if(s=='-')f=-1;s=gc();}
	while(isdigit(s)){x=x*10+s-'0';s=gc();}
	return x*f;
}
void write(int x)
{
	if (x>=10) write(x/10);
	putchar('0'+x%10);
}
struct Hash
{
	int a;
}z[N*2];
Hash h[N*2];
Hash operator +(Hash a,Hash b){add(a.a,b.a,p1);return a;}
Hash operator -(Hash a,Hash b){del(a.a,b.a,p1);return a;}
Hash operator *(Hash a,Hash b){mul(a.a,b.a,p1);return a;}
Hash operator *(Hash a,int b){mul(a.a,b,p1);return a;}
bool operator ==(Hash a,Hash b){return a.a==b.a;}
Hash ask(int l,int r){return h[r]-h[l-1]*z[r-l+1];}
void dfs(int x,int father)
{
	sz[x]=1;fa[x]=father;
	for (int u:e[x]) if (u!=fa[x])
	{
		de[u]=de[x]+1;
		dfs(u,x);
		sz[x]+=sz[u];
		if (sz[u]>sz[son[x]]) son[x]=u;
	}
}
void dfs1(int x,int t)
{
	tp[x]=t;dfn[x]=++cnt;tr[cnt]=x;
	if (son[x]) dfs1(son[x],t);
	for (int u:e[x]) if (u!=fa[x]&&u!=son[x]) dfs1(u,u);
}
int rev(int x){return 2*n+1-x;}
void LCA(int a,int b,node sh[],int &w)
{
	static node R[210];
	int wr=0,ta,tb;w=0;
	while (tp[a]!=tp[b])
	{
		ta=tp[a],tb=tp[b];
		if (de[ta]>de[tb])
		{
			sh[++w]=(node){rev(dfn[a]),rev(dfn[ta])};
			a=fa[ta];
		}
		else
		{
			R[++wr]=(node){dfn[tb],dfn[b]};
			b=fa[tb];
		}
	}
	if (de[a]>de[b]) sh[++w]=(node){rev(dfn[a]),rev(dfn[b])};
	else R[++wr]=(node){dfn[a],dfn[b]};
	for (int i=wr;i>=1;i--) sh[++w]=R[i];
}
int lcp(int a,int b,int c,int d)
{
	if (ch[a]!=ch[c]) return 0;
	int l=1,r=min(b-a+1,d-c+1);
	while (l<r)
	{
		int mid=l+((r-l+1)>>1);
		if (ask(a,a+mid-1)==ask(c,c+mid-1)) l=mid;
		else r=mid-1;
	}
	return l;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) s[i]=gc();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,0);dfs1(1,1);
	for (int i=1;i<=n;i++) ch[dfn[i]]=s[i],ch[2*n+1-dfn[i]]=s[i];
	z[0]=(Hash){1};
	for (int i=1;i<=2*n;i++) z[i]=z[i-1]*base;
	for (int i=1;i<=2*n;i++) h[i]=h[i-1]*base+(Hash){ch[i]-'a'};
	int q=read();
	while (q--)
	{
		int a=read(),b=read(),c=read(),d=read(),wa=0,wb=0,ans=0;
		LCA(a,b,A,wa);LCA(c,d,B,wb);
		reverse(A+1,A+1+wa);reverse(B+1,B+1+wb);
		while (wa&&wb)
		{
			int l=A[wa].l,r=A[wa].r,L=B[wb].l,R=B[wb].r;
			int len=min(r-l+1,R-L+1);
			Hash ta=ask(l,l+len-1),tb=ask(L,L+len-1);
			if (r-l+1<=R-L+1)
			{
				if (ta==tb)
				{
					ans+=len;wa--;
					if (L+len<=R) B[wb]=(node){L+len,R};
					else wb--;
				}
				else{ans+=lcp(l,r,L,R);break;}
			}
			else
			{
				if (ta==tb) ans+=len,wb--,A[wa]=(node){l+len,r};
				else{ans+=lcp(l,r,L,R);break;}
			}
		}
		write(ans);putchar('\n');
	}
}