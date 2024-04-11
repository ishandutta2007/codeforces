#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG LL i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG LL i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 410000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,m;
LL r;
LL f;
LL a[MAXN];
LL b[MAXN];
LL mx=0;
int main()
{
	cin>>n>>m;
	r=m*8/n;
	//WRT(r);
	if (r>52)
		f=LLINF/4;
	else
		f=(LL)1<<r;
	//WRT(f);
	f--;
	RPT(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	int cnt=0;
	RPT(i,0,n)
	{
		if (i==0 || a[i]!=a[i-1])
			b[i]=++cnt;
		else
			b[i]=cnt;
	}
	b[n]=LLINF;
	LL pl,pr;
	pl=0;
	pr=0;
	while (b[pr]-b[pl]<=f)
		pr++;
	mx=pr-pl;
	while (pr<n)
	{
		//cout<<pl<<' '<<pr<<endl;
		pl++;
		while (b[pr]-b[pl]<=f)
			pr++;
		mx=max(mx,pr-pl);
	}
	cout<<n-mx;
	return ~~(0^_^0);
}