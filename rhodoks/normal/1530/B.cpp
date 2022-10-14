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

typedef pair<int,int> pii;

void init()
{

}

bool isnei(pii p1,pii p2)
{
	return max(abs(p1.first-p2.first),abs(p1.second-p2.second))<=1;
}
void work()
{
	int h,w;
	cin>>h>>w;
	vector<pii> v;
	for (int i=1;i<=w;i++)
		v.push_back({1,i});
	for (int i=2;i<h;i++)
		v.push_back({i,w});
	for (int i=w;i>=1;i--)
		v.push_back({h,i});
	for (int i=h-1;i;i--)
		v.push_back({i,1});
	vector<pii> ans;
	ans.push_back(v[0]);
	for (int i=1;i<v.size();i++)
	{
		bool flag=true;
		for (auto p:ans)
			if (isnei(p,v[i]))
				flag=false;
		if (flag)
			ans.push_back(v[i]);
	}
	char s[40][40];
	MST(s,0);
	for (int i=0;i<h;i++)
		for (int j=0;j<w;j++)
			s[i][j]='0';
	for (auto p:ans)
		s[p.first-1][p.second-1]='1';
	for (int i=0;i<h;i++)
		cout<<s[i]<<endl;
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