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
int n,x,y,mid;
int dp[MAXN];
int ans=0;

void dfs(int pos,int f)
{
	dp[pos]=0;
	vector<int> tmp;
	for (auto p:g[pos])
		if (p!=f)
		{
			//if (!dfs(p,pos))
			//	return false;
			dfs(p,pos);
			tmp.push_back(dp[p]);
		}
	sort(tmp.begin(),tmp.end());
	if (pos==1)
	{
		tmp[tmp.size()-1]--;
		for (auto p:tmp)
		{
			//WRT(p);
			ans=max(ans,p+2);
		}
		return;
	}
	if (tmp.size()==1)
	{
		dp[pos]=tmp[0]+1;
		//if (dp[pos]>mid)
		//	return false;
	}
	else if (tmp.size()>=2)
	{
		for (int i=1;i<tmp.size();i++)
		{
			//WRT(pos)
			//WRT(tmp[i])
			ans=max(ans,tmp[i]+2);
		}
		dp[pos]=tmp[0]+1;
	}
	ans=max(ans,dp[pos]);
	//cout<<pos<<' '<<dp[pos]<<endl;
}


void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		g[i].clear();
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ans=0;
	dfs(1,1);
	printf("%d\n",ans);
	/*
	int l=1,r=n;
	while (l<n)
	{
		int mid=(l+r)/2;
		if (check())
			mid=r;
		else
			mid=l+1;
	}
	*/
} 

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}