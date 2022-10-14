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

LL f[MAXN];
LL L,R;
LL g[33][33];
void init()
{

}

void work()
{
	f[0]=1;
	f[1]=1;
	for (int i=2;i<=32;i++)
		f[i]=f[i-1]*2;
	cin>>L>>R;
	for (int i=2;i<=32;i++)
		for (int j=i+1;j<=32;j++)
			g[i][j]=f[32-j];
	if (L==1)
	{
		g[1][32]=1;
		L++;
	}
	LL len=(R-L+1);
	WRT(len)
	for (int i=31;i>=2;i--)
	{
		if ((len>>(31-i))&1)
		{
			g[1][i]=L-1;
			L+=f[32-i];
			WRT(i);
		}
	}
	WRT(L)
	WRT(R)
	int cnt=0;
	for (int i=1;i<=32;i++)
		for (int j=1;j<=32;j++)
			if (g[i][j]>0 && g[i][j]<1000000)
				cnt++;
	cout<<"YES"<<endl;
	cout<<32<<' '<<cnt<<endl;
	for (int i=1;i<=32;i++)
		for (int j=1;j<=32;j++)
			if (g[i][j]>0 && g[i][j]<1000000)
				cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
	
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