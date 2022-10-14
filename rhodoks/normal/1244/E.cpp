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

LL n;
LL k;
LL a[201000];
LL lsum,lval,rsum,rval;
int main()
{
	cin>>n>>k;
	for (LL i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	lval=a[1];
	for (LL i=1;i<=n;i++)
		if (a[i]==a[1])
			lsum++;
	rval=a[n];
	for (LL i=n;i;i--)
		if (a[i]==a[n])
			rsum++;
	LL ans=rval-lval;
	while (1)
	{
		//cout<<lsum<<' '<<lval<<' '<<rsum<<' '<<rval<<endl;
		if (rval-lval==0)
			break;
		if (k<lsum && k<rsum)
			break;
		if (lsum<rsum)
		{
			LL tmp=min(a[lsum+1]-lval,k/lsum);
			lval+=tmp;
			ans-=tmp;
			k-=tmp*lsum;
			for (LL i=lsum+1;a[i]==lval && i<=n ;i++)
				lsum++;
		}
		else
		{
			LL tmp=min(rval-a[n-rsum],k/rsum);
			rval-=tmp;
			ans-=tmp;
			k-=tmp*rsum;
			for (LL i=n-rsum;a[i]==rval && i;i--)
				rsum++;
		}
	}
	cout<<rval-lval;
	return ~~(0^_^0);
}