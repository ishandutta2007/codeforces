#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];

typedef int integer;
void GetPrimeFactor(integer x)
{
	integer i;
	for (i=2;i*i<=x;i++)
	{
		int sum=0;
		while (x%i==0)
		{
			sum++;
			x/=i;
		}
		if (sum)
			g[i].push_back(sum);
	}
	if (x>=2)
		g[x].push_back(1);
}


int n;
int a[MAXN];
 
int main()
{
	LL ans=1;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		GetPrimeFactor(a[i]);
	}
	for (int i=2;i<MAXN;i++)
		if (g[i].size()>=n-1)
		{
			sort(g[i].begin(),g[i].end());
			int c;
			if (g[i].size()==n)
				c=g[i][1];
			else
				c=g[i][0];
			while (c--)
			{
				ans*=i;
			}
		}
	cout<<ans;
	return ~~(0^_^0);
}