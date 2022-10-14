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

int a[MAXN];
int in[MAXN];
/*
vector<int> g[MAXN];
int ans[MAXN];
int ring[MAXN];
int stak[MAXN];
int cnt=0;
*/
int visit[MAXN];
int from[MAXN];
int ans[MAXN];
typedef pair<int,int> pii;
void init()
{

}
/*
void dfs1(int pos,int f)
{
	stak[++cnt]=pos;
	for (auto p:g[pos])
	{
		if (p==f)
			continue;
		if (visit[p])
		{
			for (int i=1
		}
	}
}
*/
void work()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		in[i]=visit[i]=from[i]=ans[i]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		in[a[i]]++;
		/*
		g[i].clear();
		visit[i]=ring[i]=stak[i]=0;
		*/
	}
	vector<pii> v;
	for (int i=1;i<=n;i++)
	{
		//WRT(in[i]);
		if (in[i]==0)
		{
			pii tmp;
			//WRT(i);
			tmp.first=i;
			int pos=i;
			while (visit[pos]==0)
			{
				visit[pos]=1;
				if (visit[a[pos]]==0)
				{
					ans[pos]=a[pos];
					pos=a[pos];
				}
				else
					break;
			}
			tmp.second=pos;
			//WRT(pos);
			v.push_back(tmp);
			//cout<<tmp.first<<' '<<tmp.second<<endl;
		}
		
	}
	int m=v.size();
	WRT(m);
	if (m==1)
	{
		ans[v[0].second]=v[0].first; 
		v.pop_back();
	}
	for (int i=0;i<v.size();i++)
		ans[v[i].second]=v[(i+m+1)%m].first;
	for (int i=1;i<=n;i++)
		if (ans[i]==0)
			ans[i]=a[i];
	int sum=0;
	for (int i=1;i<=n;i++)
		sum+=(ans[i]==a[i]);
	cout<<sum<<endl;
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	cout<<endl;
	/*
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		//g[i].push_back(a[i]);
		//g[a[i]].push_back(i);
		if (in[i]==0)
			q.push(i);
	}
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		int p=a[pos];
		{
			if (ans[pos]==0 && visit[p]==0)
			{
				ans[pos]=p;
				from[p]=pos;
				visit[p]=1;
			}
			in[p]--;
			if (in[p]==0)
			{
				q.push(p);
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (in[ans[i]])
			ans[i]=0;
	MRK();
	vector<int> pin,pout;
	for (int i=1;i<=n;i++)
	{
		if (in[i])
			ans[i]=a[i];
		else 
		{
			if (ans[i]==0)
				pout.push_back(i);
			if (from[i]==0)
				pin.push_back(i);
		}
	}
	WRT(pin.size());
	WRT(pout.size());
	for (int i=0;i<pin.size();i++)
		ans[pout[i]]=pin[i];
	int sum=0;
	for (int i=1;i<=n;i++)
		sum+=(ans[i]==a[i]);
	cout<<sum<<endl;
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	cout<<endl;
	*/
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}