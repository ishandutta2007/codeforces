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

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL f[MAXN];
int main()
{
	LL n;
	cin>>n;
	int ff=0;
	int cnt=0;
	RPT(i,0,n)
	{
		cin>>ff;
		f[cnt++]=ff;
	}
			
	sort(f,f+cnt);
	LL ans=0;
	LL pp=0;
	RPT(i,0,cnt)
	{
		LL* l=lower_bound(f,f+cnt,-2*abs(f[i]));
		LL* r=upper_bound(f,f+cnt,-1*abs(f[i]));
		int tem1=*(r-1);
		ans+=r-l-1;
		r=lower_bound(f,f+cnt,1*abs(f[i]));
		l=upper_bound(f,f+cnt,2*abs(f[i]));
		int tem2=*(r);
		if (tem1==-tem2 && abs(tem1)==abs(f[i]))
			pp++;
		ans+=l-r;
		if (f[i]==0)
			ans--;
	}
	ans-=pp/2;
	cout<<ans;
	return ~~(0^_^0);
}