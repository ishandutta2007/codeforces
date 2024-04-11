#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef  LL integer;
void GetPrimeFactor(map<integer,int> &mp,integer x)
{
	mp.clear();
	integer i;
	for (i=2;i*i<=x;i++)
		while (x%i==0)
		{
			mp[i]++;
			x/=i;
		}
	if (x>=2)
		mp[x]++;
}
map<LL,int> mp;

LL mpow(LL x,LL n)
{
	
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x;
		x=x*x;
		n>>=1;
	}
	return ans;
} 

void work()
{
	map<LL,int> tmp;
	vector<LL> v;
	LL p,q;
	cin>>p>>q;
	LL gp=p;
	GetPrimeFactor(mp,q);
	for (auto x:mp)
	{
		//cout<<x.first<<' '<<x.second<<endl;
		while (p%x.first==0)
		{
			p/=x.first;
			tmp[x.first]++;
		}
		v.push_back(x.first);
	}
	if (gp%q==0)
	{
		LL mi=LLINF;
		for (auto p:v)
			if (mpow(p,tmp[p]-mp[p]+1)<mi)
				mi=mpow(p,tmp[p]-mp[p]+1);
		cout<<gp/mi<<endl;
	}
	else
		cout<<gp<<endl;
} 
 
int main()
{
	int t;
	cin>>t;
	while(t--)work();
	return ~~(0^_^0);
}