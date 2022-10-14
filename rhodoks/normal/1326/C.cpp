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

int p[MAXN];
int n,k;
vector<int> v;
int main()
{
	LL ans=1;
	LL val=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if (p[i]>=n-k+1)
		{
			v.push_back(i);
			val+=p[i];
		}
	}
	for (int i=1;i<v.size();i++)
		ans=ans*(v[i]-v[i-1])%MOD;
	cout<<val<<' '<<ans<<endl;
	return ~~(0^_^0);
}