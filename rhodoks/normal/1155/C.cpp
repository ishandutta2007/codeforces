#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 610000
#define MAXM 610000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL gcd(LL a,LL b)
{
	if (b==0)
		return a;
	if (a<b)
		swap(a,b);
	return gcd(b,a%b);
}

LL x[MAXN];
LL n,m;
int main()
{
	cin>>n>>m;
	RPT(i,0,n)
		cin>>x[i];
	//sort(x,x+n);
	LL tem=-1;
	RPT(i,1,n)
		if (x[i]!=x[i-1])
			if (tem!=-1)
				tem=gcd(tem,x[i]-x[i-1]);
			else
				tem=x[i]-x[i-1];
	LL y;
	RPT(i,0,m)
	{
		cin>>y;
		if (tem%y==0)
		{
			cout<<"YES"<<endl;
			cout<<x[0]<<' '<<i+1;
			return 0;
		}
	}
	cout<<"NO";
	
	return ~~(0^_^0);
}