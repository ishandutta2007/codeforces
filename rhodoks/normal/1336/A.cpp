#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
int size[MAXN];
int depth[MAXN];
int n,k;
void init()
{
	int x,y;
	cin>>n>>k;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

vector<int> ans;
void dfs(int pos,int f)
{
	size[pos]=1;
	depth[pos]=depth[f]+1;
	for (auto p:g[pos])
		if (p!=f)
		{
			dfs(p,pos);
			size[pos]+=size[p];
		}
	ans.push_back(depth[pos]-size[pos]);
	//cout<<pos<<' '<<depth[pos]<<' '<<size[pos]<<endl;
}

int main()
{
	init();
	dfs(1,1);
	sort(ans.begin(),ans.end());
	LL sum=0;
	for (int i=0;i<k;i++)
		sum+=ans[n-1-i];
	cout<<sum;
	return ~~(0^_^0);
}