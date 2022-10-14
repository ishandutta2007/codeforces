#include <bits/stdc++.h>
#define DB double
#define LL long long

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

LL n,k;
LL count(LL x)
{
	if (x<=0)
		return -1;
	LL ans=0;
	if (x&1)	
	{
		LL tmp=1;
		while (n>=x)
		{
			ans+=min(tmp,n-x+1);
			tmp<<=1;
			x<<=1;
		}
	}
	else
	{
		LL tmp=2;
		while (n>=x)
		{
			ans+=min(tmp,n-x+1);
			tmp<<=1;
			x<<=1;
		}
		
	}
	return ans;
}

int main()
{
	cin>>n>>k;
	//WRT(count(2));
	if (n<=10)
		for (int i=n;i;i--)
			if (count(i)>=k)
			{
				cout<<i;
				return 0;
			}
	LL l,r;
	l=0;
	r=n/2;
	while (l<r)
	{
		LL mid=(l+r+1)/2;
		//cout<<mid<<' '<<count(mid*2)<<endl;
		if (count(mid*2)>=k)
			l=mid;
		else
			r=mid-1;
	}
	LL ans=2*l;
	l=0;
	r=(n+1)/2;
	while (l<r)
	{
		LL mid=(l+r+1)/2;
		if (count(mid*2-1)>=k)
			l=mid;
		else
			r=mid-1;
	}
	ans=max(ans,2*r-1);
	cout<<ans;
	return ~~(0^_^0);
}