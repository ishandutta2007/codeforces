#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;
LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
} 

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

LL inv2=inv(2);
vector<int> g[MAXN];
int n;
int depth[MAXN];
int size[MAXN];
int son[MAXN];
int fa[MAXN];
int top[MAXN];
void dfs(int pos,int f)
{
	if (pos==f)
		depth[pos]=0;
	fa[pos]=f;
	size[pos]=1;
	depth[pos]=depth[f]+1;
	son[pos]=0;
	for (auto p:g[pos])
		if (p!=f)
		{
			dfs(p,pos);
			size[pos]+=size[p];
			if (size[p]>size[son[pos]])
				son[pos]=p;
		}
}

void dfs2(int pos,int topf)
{
	top[pos]=topf;
	if (son[pos])
		dfs2(son[pos],topf);
	for (auto p:g[pos])
		if (p!=son[pos] && p!=fa[pos])
			dfs2(p,p);
}

int lca(int x,int y)
{
	int *k;
	while (top[x]!=top[y])
	{
		k=depth[top[x]]>depth[top[y]] ? &x:&y;
		*k=fa[top[*k]];
	}
	return depth[x]>depth[y]? y:x;
}

LL prob[410][410];
LL sumprob[410][410];
void init()
{
	prob[0][0]=1;
	for (int i=0;i<=400;i++)
		for (int j=0;j<=400;j++)
		{
			prob[i][j]%=MOD;
			/*
			sumprob[i][j]+=prob[i][j];
			if (j>0)
				sumprob[i][j]+=sumprob[i][j-1];
			sumprob[i][j]%=MOD;
			*/
			prob[i+1][j]+=prob[i][j]*inv2%MOD;
			prob[i][j+1]+=prob[i][j]*inv2%MOD;
		}
	for (int i=0;i<=200;i++)
		for (int j=0;j<=200;j++)
		{
			for (int k=0;j-k>=0;k++)
				sumprob[i][j]+=prob[i+k][j-k];
			sumprob[i][j]%=MOD;
		}
}

void work()
{
	LL ans=0;
	int x,y;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for (int i=1;i<=n;i++)
	{
		dfs(i,i);
		dfs2(i,i);
		for (int x=1;x<=n;x++)
			for (int y=x+1;y<=n;y++)
			{
				if (x==y)
					continue;
				int lc=lca(x,y);
				if (lc==y)
				{
					ans++;
					continue;
				}
				if (lc==x)
					continue;
				
				int dx=depth[x]-depth[lc];
				int dy=depth[y]-depth[lc];
				//cout<<i<<' '<<x<<' '<<y<<' '<<lc<<endl;
				//WRT(sumprob[dy][dx-1]);
				ans+=sumprob[dy][dx-1];
			}
	}
	cout<<(ans%MOD)*inv(n)%MOD<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}