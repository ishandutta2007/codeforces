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

int n;
string s;
string a,b;
void init()
{

}

void work()
{
	a.clear();
	b.clear();
	cin>>n;
	cin>>s;
	int cnt[2]={0,0};
	for (auto p:s)
		cnt[p-'0']++;
	if (cnt[0]&1 || s[0]=='0' || s[s.size()-1]=='0')
	{
		cout<<"NO"<<endl;
		return;
	}
	int tot[2]={0,0};
	cout<<"YES"<<endl;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='1')
		{
			if (tot[1]*2<cnt[1])
			{
				a.push_back('(');
				b.push_back('(');
			}
			else
			{
				a.push_back(')');
				b.push_back(')');
			}
			tot[1]++;
		}
		else
		{
			
			if (tot[0]&1)
			{
				a.push_back('(');
				b.push_back(')');
				
			}
			else
			{
				a.push_back(')');
				b.push_back('(');
			}
			tot[0]++;
		}
	}
	cout<<a<<endl<<b<<endl;
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