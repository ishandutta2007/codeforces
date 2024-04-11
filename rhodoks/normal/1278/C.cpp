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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> v[200100];
int jam[210000];
int main()
{
	int t;
	cin>>t;
	int n;
	while (t--)
	{
		int d=0;
		cin>>n;
		for (int i=1;i<=2*n;i++)
		{
			scanf("%d",&jam[i]);
			if (jam[i]==1)
				d++;
			else
				d--;
		}
		for (int i=max(0,100000-2*n-5);i<=min(200010,100000+2*n+5);i++)
			v[i].clear();
		int sum=100000;
		v[100000].push_back(0);
		for (int i=1;i<=n;i++)
		{
			if (jam[i+n]==1)
				sum++;
			else
				sum--;
			v[sum].push_back(i);
		}
	
		int ans=INF;
		//WRT(d);
		//WRT(100000+d);
		//if (v[100000+d].size())
		//	WRT(v[100000+d][0]);
		if (100000+d<=200000 && 100000+d>=1 && v[100000+d].size()>0)
			ans=min(ans,v[100000+d][0]);
		sum=100000;
		for (int i=n;i>=1;i--)
		{
			//cout<<i<<endl;
			if (jam[i]==1)
				sum--;
			else
				sum++;
			if (sum+d>=1 && sum+d<=200000 && v[sum+d].size()>0 )
				ans=min(ans,v[sum+d][0]+n-i+1);
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}