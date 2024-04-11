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
int a[510]; 
int cnt[510];
int s[510][510];
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i][i]=a[i];
		cnt[a[i]]=a[i]-1;
	}
	for (int i=2;i<=n;i++)
	{
		vector<int> v;
		for (int j=1;j<=n;j++)
			if (a[j]>=i)
				v.push_back(a[j]);
		for (int y=1;y<=n-i+1;y++)
		{
			int x=i+y-1;
			s[x][y]=v[y-1];
			/*
			if (cnt[s[x-1][y]])
			{
				s[x][y]=s[x-1][y];
				cnt[s[x][y]]--;
			}
			else
			{
				s[x][y]=s[x][y+1];
				cnt[s[x][y+1]]--;
			}
			cout<<x<<' '<<y<<' '<<s[x][y]<<endl;
			*/
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
			cout<<s[i][j]<<' ';
		cout<<endl;
	}
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
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