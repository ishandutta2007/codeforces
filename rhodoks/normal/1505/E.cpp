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

#define MAXN 101
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN][MAXN];
int n,m;
int px,py;
void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>s[i];
	int px=0;
	int py=0;
	int ans=0;
	if (s[px][py]=='*')
		ans++;
	while (1)
	{
		bool f=0;
		for (int i=1;i<=10;i++)
			for (int j=0;j<=i;j++)
				if (s[px+j][py+i-j]=='*')
				{
					if (f)
						continue;
					f=1;
					px=px+j;
					py=py+i-j;
					ans++;
				}
		if (f==0)
			break;
	}
	cout<<ans<<endl;
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