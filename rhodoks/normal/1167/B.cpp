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

int main()
{
	LL p[100];
	LL n[100];
	LL s=4*8*15*16*23*42;
	LL pos=6;
	RPT(i,1,5)
	{
		cout<<"? "<<i<<' '<<i+1<<endl;
		fflush(stdout);
		cin>>n[i];
		if (n[i]%23==0)
			pos=i;
	}
	if (n[4]%23==0 && n[3]%23!=0)
		pos=5;
	p[pos]=23;
	if (pos==6)
	{
		p[3]=s/23/n[1]/n[4];
		RPT(i,3,5)
			p[i+1]=n[i]/p[i];
		DRPT(i,2,0)
			p[i]=n[i]/p[i+1];
	}
	if (pos!=6)
	{
		RPT(i,pos,5)
			p[i+1]=n[i]/p[i];
		DRPT(i,pos-1,0)
			p[i]=n[i]/p[i+1];
		p[6]=s;
		RPT(i,1,6)
			p[6]/=p[i];
	}
	cout<<"!"<<' ';
	RPT(i,1,7)
		cout<<p[i]<<' ';
	return ~~(0^_^0);
}