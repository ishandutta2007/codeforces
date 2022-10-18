#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rbtree;
typedef long long ll;
const int N=6e5+20;
rbtree e[N];
char t[N];
int a[N],sum[N],id[N],ys[N],st[N],pp[N],f[N];
int ti[128],cnt,low[N];
ll g[N];
void add(int u,int v){e[u].insert(v);f[v]=u;}
int dfs1(int l,int r)
{
	id[l]=++cnt;id[r]=cnt;
	int i,j;
	for (i=l+1;i<r;i=j+1)
	{
		assert(t[i]=='(');
		j=pp[i];
		add(id[l],dfs1(i,j));
	}
	return id[l];
}
template<typename typC,int N> struct bit
{
	typC a[N],s[N];
	int n;
	bit()
	{
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
		memset(s+1,0,n*sizeof a[0]);
	}
	void init(int nn,typC *b)
	{
		n=nn;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=s[x]+a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bit<ll,N> s1;
void dfs2(int u)
{
	low[u]=u;
	for (int v:e[u]) dfs2(v),low[u]=low[v];
}
ll C(int n){return (ll)n*(n-1)>>1;}
int main()
{
	ti['(']=1;ti[')']=-1;
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q,tp=0,i,j,w,x;
	string S;
	cin>>n>>q>>S;
	for (i=1;i<=n;i++) a[i]=a[i-1]+ti[S[i-1]];
	w=-*min_element(a+1,a+n+1)+1;
	for (i=1;i<=n;i++) ys[i]=i+w;
	for (i=1;i<=w;i++) t[i]='(';
	for (i=1;i<=n;i++) t[i+w]=S[i-1];
	for (i=n;i;i--) a[i]=a[i+1]-ti[S[i-1]];
	x=-*min_element(a+1,a+n+1)+1;
	for (i=1;i<=x;i++) t[i+w+n]=')';
	n+=w+x;
	assert(n%2==0&&n<N);
	for (i=1;i<=n;i++) if (ti[t[i]])
	{
		if (t[i]=='(') st[++tp]=i; else pp[st[tp]]=i,pp[i]=st[tp--];
	} else assert(t[i]=='.');
	assert(!tp);
	dfs1(1,n);dfs2(1);
	for (i=1;i<=n;i++) g[i]=e[i].size()*(e[i].size()-1ll)+2>>1;
	s1.init(n,g);
	while (q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		l=id[ys[l]];r=id[ys[r]];
		int u=f[l];
		if (t==2) cout<<s1.sum(l,low[r])+C(e[u].order_of_key(r+1)-e[u].order_of_key(l))<<'\n'; else s1.mdf(l,-1),e[u].erase(l),s1.mdf(u,-(int)e[u].size());
	}
}