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

int n;
int a[MAXN];
void work()
{
	int cnt[33];
	MST(cnt,0);
	int xorsum=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		xorsum^=a[i];
		for (int j=0;j<=30;j++)
			cnt[j]+=(a[i]>>j)&1;
	}
	for (int i=30;i>=0;i--)
	{
		if ((xorsum>>i) & 1)
		{
			if ((cnt[i]-1)%4==0)
			{
				printf("WIN\n");
				return;
			}
			else
			{
				if (n&1)
				{
					printf("LOSE\n");
					return;
				}
				else
				{
					printf("WIN\n");
					return;
				}
			}
		}
	}
	printf("DRAW\n");
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		work();
	}
	return ~~(0^_^0);
}