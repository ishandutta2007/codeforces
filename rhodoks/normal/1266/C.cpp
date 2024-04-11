#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int x[510],y[510];
int r,c;
int main()
{
	cin>>r>>c;
	if (r==1 && c==1)
	{ 
		cout<<0;
		return 0;
	}
	if (r==1 )
		for (int i=2;i<=c+1;i++)
			cout<<i<<' ';
	if (c==1)
		for (int i=2;i<=r+1;i++)
			cout<<i<<endl;
	if (r>=2 && c>=2)
	{
		x[0]=2;
		x[1]=3;
		y[0]=4;
		y[1]=1;
		for (int i=2;i<c;i++)
			x[i]=i+3;
		for (int i=2;i<r;i++)
			y[i]=i+c+1;
		for (int i=0;i<r;i++)
		{
			for (int j=0;j<c;j++)
				cout<<x[j]*y[i]<<' ';
			cout<<endl;
		}
	}
	return ~~(0^_^0);
}