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

#define MAXN 10000
#define MAXM 10000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int main()
{
	LL l,r;
	cin>>l>>r;
	LL pos=1;
	LL cnt=0;
	LL st1=0,st2=0;
	LL f=1;
	LL ans=0;
	while (1)
	{
		if (pos>r)
			break;
		cnt++;
		LL x1=pos,x2=(pos<<1)-1;
		if (x1<=l)
			x1=l;
		if (x2>=r)
			x2=r;
		if (x1<=x2)
		{
			if (cnt&1 ==1)
				ans=ans+(((st1+x1-pos+1)+(st1+x2-pos+1)-1)%MOD)*((x2-x1+1)%MOD);
			else
				ans=ans+(((st2+x1-pos+1)+(st2+x2-pos+1))%MOD)*((x2-x1+1)%MOD);
			ans%=MOD;
		}
		if (cnt&1)
			st1+=pos;
		else
			st2+=pos;
		pos<<=1;
	}
	cout<<ans;
	return ~~(0^_^0);
}