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
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
int size[MAXN]; 
int l[MAXN];
int n,x;
vector<int> ans;

bool cmp(int x,int y)
{
	//return l[x]+size[x]<l[y]+size[y];
	//if (size[x]==size[y])
	//	return l[x]<l[y];
	return l[x]<l[y];
	return size[x]<size[y];
}

void dfs1(int pos)
{
	l[pos]=1;
	size[pos]=1;
	for (auto p:g[pos])
	{
		dfs1(p);
		l[pos]=max(l[pos],l[p]+1);
		size[pos]+=size[p];
	}
	sort(g[pos].begin(),g[pos].end(),cmp);
	int id=-1;
	//for (int i=0;i<g[pos].size()-1;i++)
	//	if (g[pos].size()-i-1
}

int dfs2(int pos,int k)
{
	int sum=0;
	int len=0;
	while (k--)
		ans.push_back(pos);
	printf("%d ",pos);
	for (auto p:g[pos])
	{
		len=dfs2(p,len);
		sum+=size[p];
	}
	return len+1;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n;
	for (int i=1;i<n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i);
	}
	dfs1(0);
	dfs2(0,0);
	cout<<endl<<ans.size()<<endl;
	for (auto p:ans)
		printf("%d ",p);
	return ~~(0^_^0);
}