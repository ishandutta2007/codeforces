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

string s,t;
void init()
{

}

void work()
{
	cin>>s>>t;
	string tmp;
	for (int i=0;i<s.size();i++)
		for (int j=i;j<s.size();j++)
		{
			tmp.clear();
			for (int k=i;k<=j;k++) 
				tmp.push_back(s[k]);
			for (int k=j-1;tmp.size()<t.size() && k>=0;k--)
				tmp.push_back(s[k]);
			//WRT(tmp);
			if (tmp==t)
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	cout<<"NO"<<endl;
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