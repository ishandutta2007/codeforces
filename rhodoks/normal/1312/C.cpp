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

#define int LL

int t,k;
int a[MAXN];
int n;
int buc[200];
signed main()
{
	cin>>t;
	while (t--)
	{
		int mx=0;
		bool ok=1;
		cin>>n>>k;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		MST(buc,0);
		while (mx)
		{
			mx/=k;
			int cnt=0;
			for (int i=0;i<n;i++)
			{
				if (a[i]%k>1)
					ok=0;
				if (a[i]%k==1)
					cnt++;
				a[i]/=k;
			}
			if (cnt>1)
				ok=0;
			if (!ok)
				break;
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return ~~(0^_^0);
}