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

LL mp[MAXN<<3]; 
int n;

int main()
{
	cin>>n;
	int x;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[i-x+MAXM]+=x;
	}
	LL ans=0;
	for (int i=0;i<(MAXN<<3);i++)
		ans=max(ans,mp[i]);
	cout<<ans;
	return ~~(0^_^0);
}