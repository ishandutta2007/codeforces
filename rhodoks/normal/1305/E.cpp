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

int n,m;
int ans[MAXN];
int sum=0;
int tmp=0;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		ans[i]=19260817+114514*i;
	if (m!=0)
	for (int i=1;i<=n;i++)
	{
		ans[i]=i;
		sum+=(i-1)/2;
		//WRT(sum);
		if (sum==m)
			break;
		if (sum>=m)
		{
			sum-=(i-1)/2;
			ans[i]=2*(i-1)+2*(sum-m);
			//WRT();
			break;
		}
		tmp=i+1;
	}
	if (tmp==n+1)
	{
		cout<<-1;
		return 0;
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return ~~(0^_^0);
}