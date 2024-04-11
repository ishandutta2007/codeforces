/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=4*1e5+100;
int t,n,m,p[N],b[N],w,vi[N],pos[N],pre[N],suc[N];
vector <int> ok[N],f[N];
struct node
{
	int l,r,id;
}sh[N];
node a[N];
bool cmp(node a,node b){return (a.l<b.l||(a.l==b.l&&a.r>b.r));}
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit
{
	int sh[N];
	inline void clear(){for (int i=1;i<=w;i++) sh[i]=0;}
	inline int lowbit(int x){return x&(-x);}
	inline void change(int x,int v){while(x<=w)sh[x]+=v,x+=lowbit(x);}
	inline int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
}T;
void init()
{
	w=0;
	for (int i=1;i<=n+m;i++) b[++w]=a[i].r;
	sort(b+1,b+1+w);
	w=unique(b+1,b+1+w)-b-1;
	for (int i=1;i<=n+m;i++) a[i].r=lower_bound(b+1,b+1+w,a[i].r)-b;
	sort(a+1,a+1+n+m,cmp);
	T.clear();
	for (int i=n+m;i>=1;i--)
	{
		if (T.query(a[i].r)) vi[a[i].id]=1;
		T.change(a[i].r,1);
	}
	w=0;
	for (int i=1;i<=m;i++) if (!vi[i]) a[++w]=sh[i];
	for (int i=1;i<=w;i++) sh[i]=a[i];
	m=w;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) p[i]=read();
		for (int i=1;i<=m;i++) sh[i]=(node){read(),read(),i};
		for (int i=1;i<=n;i++) sh[i+m]=(node){p[i],p[i],i+m};
		for (int i=1;i<=n+m;i++) a[i]=sh[i],vi[i]=0;
		init();
		if (m==0)
		{
			printf("0\n");
			continue;
		}
		sort(sh+1,sh+1+m,cmp);
		sort(p+1,p+1+n);
		pos[0]=1;
		for (int i=1;i<=n;i++)
		{
			pos[i]=pos[i-1];
			while (sh[pos[i]].l<=p[i]&&pos[i]<=m) pos[i]++;
		}
		pos[n+1]=m+1;
		for (int i=0;i<=n;i++)
		{
			ok[i].clear();
			for (int j=pos[i];j<pos[i+1];j++) ok[i].push_back(j);
			f[i].resize(len(ok[i])+1);
			for (int &j:f[i]) j=inf;
		}
		f[0].back()=0;
		//back 
		for (int i=1;i<=n;i++)
		{
			int up=len(ok[i-1])-1;
			int v1=inf,v2=inf;
			for (int j=0;j<=up;j++)
			{
				int a=f[i-1][j],b=f[i-1][j];
				if (j!=up) a+=p[i]-sh[ok[i-1][j+1]].r,b+=2*(p[i]-sh[ok[i-1][j+1]].r);
				ckmin(v1,a);ckmin(v2,b);
			}
			int a=f[i-1].back(),b=f[i-1].back();
			if (!ok[i-1].empty()) a+=p[i]-sh[ok[i-1][0]].r,b+=2*(p[i]-sh[ok[i-1][0]].r);
			ckmin(v1,a);ckmin(v2,b);
			for (int j=0;j<len(ok[i]);j++) 
			{
				int now=sh[ok[i][j]].l-p[i];
				f[i][j]=min(v1+2*now,v2+now);
			}
			int MIN=inf;
			for (int j=0;j<=up;j++)
			{
				int now=f[i-1][j];
				if (j!=up) now+=p[i]-sh[ok[i-1][j+1]].r;
				MIN=min(MIN,now);
			}
			int now=f[i-1].back();
			if (!ok[i-1].empty()) now+=p[i]-sh[ok[i-1][0]].r;
			MIN=min(MIN,now);
			f[i].back()=MIN;
		}
		int ans=inf;
		for (int i=1;i<=n;i++)
		{
			if (pos[i]==m+1) ans=min(ans,f[i].back());
			else if (pos[i+1]==m+1) ans=min(ans,f[i][len(ok[i])-1]);
		}
		printf("%lld\n",ans);
	}
}