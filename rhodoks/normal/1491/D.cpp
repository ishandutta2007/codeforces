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

int u,v;
void init()
{

}

void work()
{
	scanf("%d%d",&u,&v);
	if (v<u)
	{
		printf("NO\n");
		return;
	}
	if (v==u)
	{
		printf("YES\n");
		return;
	}
	vector<int> v1,v2;
	for (int i=0;i<30;i++)
	{
		if ((v>>i)&1)
			v1.push_back(i);
		if ((u>>i)&1)
			v2.push_back(i);
		if (v1.size()>v2.size())
		{
			printf("NO\n");
			return;
		}
		for (int i=0;i<v1.size();i++)
			if (v1[i]<v2[i])
			{
				printf("NO\n");
				return;
			}
	}
	printf("YES\n");
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