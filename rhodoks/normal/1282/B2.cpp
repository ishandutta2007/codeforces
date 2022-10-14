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

#define MAXN 310000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,p,k;
int a[MAXN];
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int ans=0;
		cin>>n>>p>>k;
		//WRT(p);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int cnt=0;
		int tmp;
		for (int it=0;it<k;it++)
		{
			p-=a[it];
			if (p<0)
				break;
			cnt=it;
			tmp=p;
			ans=max(ans,cnt);
			for (int i=it+k;i<=n;i+=k)
				if (tmp>=a[i])
				{
					tmp-=a[i];
					cnt+=k;
				}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}