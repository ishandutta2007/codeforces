#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;
typedef int integer;
void GetPrimeFactor(vector<pair<integer,int> > &v,integer x)
{
	v.clear();
	integer i;
	for (i=2;i*i<=x;i++)
		if (x%i==0)
		{
			v.push_back({i,1});
			x/=i;
			while (x%i==0)
			{
				v.back().second++;
				x/=i;
			}
		}
	if (x>=2)
		v.push_back({x,1});
}
vector<pair<integer,int> > pv;

int n,k;
int a[MAXN];
int b[MAXN];
int buc[MAXN];
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		GetPrimeFactor(pv,a[i]);
		
		for (auto &p:pv)
		{
			while (p.second>=k)
			{
				for (int j=0;j<k;j++)
				{
					p.second--;
					a[i]/=p.first;
				}
			}
		}
		b[i]=1;
		for (auto p:pv)
			if (p.second!=0)
			{
				//cout<<p.first<<" - "<<p.second<<endl;
				for (int j=0;j<k-p.second;j++)
				{
					if ((LL)b[i]*p.first>1e5)
					{
						b[i]=INF;
						break;
					}
					b[i]*=p.first;
				}
			}
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		if (b[i]<=100000)
			ans+=buc[b[i]]; 
		buc[a[i]]++;
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
}