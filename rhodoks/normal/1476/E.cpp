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

int n,m,k;
map<string,int > s[16];
vector<int> g[MAXN];
int in[MAXN];
void work()
{
	cin>>n>>m>>k;
	string tmp;
	int id;
	for (int i=1;i<=n;i++)
	{
		cin>>tmp;
		int msk=0;
		for (int j=0;j<k;j++)
			if (tmp[j]=='_')
				msk|=(1<<j);
		s[msk][tmp]=i;
	}
	
	for (int i=1;i<=m;i++)
	{
		vector<int> res;
		bool f=false;
		cin>>tmp>>id;
		
		for (int msk=0;msk<(1<<k);msk++)
		{
			string t=tmp;
			for (int j=0;j<k;j++)
				if ((msk>>j)&1)
					t[j]='_';
			if (s[msk][t])
			{
				if (id==s[msk][t])
					f=true;
				else
					res.push_back(s[msk][t]);
			}
		}
		if (!f)
		{
			cout<<"NO"<<endl;
			return;
		}
		else
		{
			for (auto p:res)
			{
				g[id].push_back(p);
				in[p]++;
			}
		}
	}
	queue<int> q;
	vector<int> ans;
	for (int i=1;i<=n;i++)
		if (in[i]==0)
			q.push(i);
	while (!q.empty())
	{
		int pos=q.front();
		ans.push_back(pos);
		q.pop();
		for (auto p:g[pos])
		{
			in[p]--;
			if (in[p]==0)
				q.push(p);
		}
	}
	if (ans.size()==n)
	{
		cout<<"YES"<<endl;
		for (auto p:ans)
			cout<<p<<' ';
	}
	else
		cout<<"NO"<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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