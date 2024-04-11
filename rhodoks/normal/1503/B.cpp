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

int mp[110][110];
int n,a;

void query(int b,int i,int j)
{
	mp[i][j]=b;
	cout<<b<<' '<<i<<' '<<j<<endl;
}

void init()
{

}

void work()
{
	cin>>n;
	for (int t=0;t<n*n;t++)
	{
		/*
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<mp[i][j]<<' ';
			cout<<endl;
		}
		*/
		bool flag=false;
		cin>>a;
		for (int i=1;i<=n;i++)	
			for (int j=1;j<=n;j++)
			{
				if ((i+j)%2+1!=a && mp[i][j]==0)
				{
					if (flag)
						break;
					flag=true;
					query((i+j)%2+1,i,j);
				} 
			}
		if (flag)
			continue;
		for (int i=1;i<=n;i++)	
			for (int j=1;j<=n;j++)
				if (mp[i][j]==0)
				{
					if (flag)
						break;
					flag=true;
					for (int k=1;k<=3;k++)
						if (k!=a && k!=mp[i-1][j] && k!=mp[i+1][j] && k!=mp[i][j-1] && k!=mp[i][j+1])
						{
							query(k,i,j);
							break;
						}
				}
	}
}

int main()
{
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
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