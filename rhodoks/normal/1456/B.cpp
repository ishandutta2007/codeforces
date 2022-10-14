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

int a[MAXN];
int sum[MAXN];
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int n,x;
	cin>>n;
	if (n>=96)
	{
		cout<<1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	int ans=INF;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=i-1;j++)
			for (int k=i;k<=n;k++)
				if ((sum[j-1]^sum[i-1])>(sum[i-1]^sum[k]))
					ans=min(ans,k-j-1);
	if (ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl; 
	return ~~(0^_^0);
}