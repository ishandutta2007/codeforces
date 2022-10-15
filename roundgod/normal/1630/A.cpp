#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n==2&&k==0) printf("0 1\n");
		else if(n<=4&&k==n-1) puts("-1");
		else
		{
			if(k!=n-1)
			{
				if(k==0)
				{

					for(int i=0;i<n/2;i++)
					{
						printf("%d %d\n",i,n-1-i);
					}
				}
				else
				{
					printf("%d %d\n",0,n-1-k);
					printf("%d %d\n",n-1,k);
					for(int i=0;i<n/2;i++)
					{
						if(i==0||i==k||i==n-1-k) continue;
						printf("%d %d\n",i,n-1-i);
					}
				}
			}
			else
			{
				printf("%d %d\n",n-1,n-2);
				printf("%d %d\n",1,3);
				printf("%d %d\n",0,n-4);
				for(int i=0;i<n/2;i++)
				{
					if(i==0||i==1||i==3) continue;
					printf("%d %d\n",i,n-1-i);
				}
			}
		}
	}
	return 0;
}