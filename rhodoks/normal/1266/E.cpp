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
#define MAXM 210000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN];
int n,q;
int s,t,u;
typedef pair<int,int> pii;
map<pii,int> mp;
int bonus[MAXN];
LL ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	cin>>q;
	int tmp;
	while (q--)
	{
		scanf("%d%d%d",&s,&t,&u);
		if ((tmp=mp[{s,t}])!=0)
		{
			bonus[tmp]--;
			//cout<<bonus[tmp]<<" - "<<a[u]<<endl;
			if (bonus[tmp]<a[tmp])
				ans++;
		}
		mp[{s,t}]=u;
		if (u!=0)
		{
			bonus[u]++;
			if (bonus[u]<=a[u])
				ans--;
		}
			printf("%lld\n",ans);
	}
	return ~~(0^_^0);
}