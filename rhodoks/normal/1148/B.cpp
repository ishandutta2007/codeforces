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

#define MAXN 501000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,m,a,b,k;
LL an[MAXN],bn[MAXN];
pair<LL,int> v[MAXN*2];

int main()
{
	cin>>n>>m>>a>>b>>k;
	if (k>=n || k>=m)
	{
		cout<<-1;
		return 0;
	}
	LL x;
	LL cnt=0;
	RPT(i,0,n)
	{
		cin>>an[i];
	}
	sort(an,an+n);
	RPT(i,0,m)
	{
		cin>>bn[i];
	}
	sort(bn,bn+m);
	int pos=0;
	LL ans=0;
	RPT(i,0,k+1)
	{
		while (bn[pos]<an[i]+a && pos!=m)
			pos++;
		if (pos+(k-i)>=m)
		{
			cout<<-1;
			return 0;
		}
		ans=max(ans,bn[pos+(k-i)]+b);
		//WRT(i);
		//WRT(pos);
		//WRT(ans);
	}
	cout<<ans;
	
	
	
	return ~~(0^_^0);
}