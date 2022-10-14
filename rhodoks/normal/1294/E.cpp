#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m;
vector<int> a[MAXN];
int buc[MAXN];

int main()
{
	int x;
	cin>>n>>m;
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			a[j].push_back(x);
		}
	for (int i=1;i<=m;i++)
	{
		//WRT(i);
		int mi=INF;
		for (int j=0;j<n;j++)
		{
			//WRT(j);
			if ((a[i][j]-1)%m==i-1 && a[i][j]<=n*m)
				buc[((-(a[i][j]-1)/m+j)%n+n)%n]++;
			//WRT(((-(a[i][j]-1)/m+j)%n+n)%n)
		}
		for (int j=0;j<n;j++)
		{
			//WRT(buc[j]);
			mi=min(mi,j+n-buc[j]);
			buc[j]=0;
		}
		//WRT(mi);
		ans+=mi;
	}
	cout<<ans;
	return ~~(0^_^0);
}