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
#define EPS 1e-8

#define _ 0
using namespace std;
#define int LL
typedef pair<int,int> pii;
LL a,b,c,d;
LL ans1,ans2;
vector<pii> v;
void init()
{

}

void dfs(LL pos,int i)
{
	if (pos>c)
		return ;
	//cout<<pos<<' '<<i<<' '<<a<<endl;
	if (pos>a)
	{
		LL x=pos;
		LL y=a*b/x;
		if (d/y*y>b && d/y*y<=d)
		{
			//cout<<x<<' '<<y<<' '<<a<<' '<<b<<endl;
			ans1=x;
			ans2=d/y*y;
			return ;
		}
	}
	if (i==v.size())
		return ;
	for (int j=0;j<=v[i].second;j++)
	{
		dfs(pos,i+1);
		if (ans1>0)
			return ;
		pos*=v[i].first;
	}
}

void work()
{
	cin>>a>>b>>c>>d;
	if (2*a<=c && 2*b<=d)
	{
		cout<<2*a<<' '<<2*b<<endl;
		return ;
	}
	ans1=ans2=-1;
	map<LL,int> mp;
	LL A=a,B=b;
	for (int i=2;i*i<=A;i++)
	{
		while (A%i==0)
		{
			A/=i;
			mp[i]++;
		}
	}
	if (A>1)
		mp[A]++;
	for (int i=2;i*i<=B;i++)
	{
		while (B%i==0)
		{
			B/=i;
			mp[i]++;
		}
	}
	if (B>1)
		mp[B]++;
	v.clear();
	for (auto p:mp)
		v.push_back(p);
	if (v.size()==0)
	{
		cout<<2<<' '<<2<<endl;
		return ;
	}
	//WRT(v.size())
	//for (auto p:v)
	//	cout<<p.first<<'-'<<p.second<<endl;
	dfs(1,0);
	swap(a,b);
	swap(c,d);
	if (ans1>0)
	{
		cout<<ans1<<' '<<ans2<<endl;
		return ;
	}
	dfs(1,0);
	cout<<ans2<<' '<<ans1<<endl;
}

signed main()
{
	init();
	int casenum=1;
	scanf("%lld",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%lld:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}