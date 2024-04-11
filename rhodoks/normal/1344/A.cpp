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

int a[MAXN];
int n;
int buc[MAXN];
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			buc[i]=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			//cout<<((a[i]+i)%n+n)%n<<endl;
			buc[((a[i]+i)%n+n)%n]++;
		}
		bool f=false;
		for (int i=0;i<n;i++)
			if (buc[i]==0)
			{
				f=true;
				cout<<"NO"<<endl;
				break;
			}
		if (!f)
			cout<<"YES"<<endl;
	}
	return ~~(0^_^0);
}