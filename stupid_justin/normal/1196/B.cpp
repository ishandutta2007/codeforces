#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
int q,n,k;
long long a[N];
int main()
{
	cin>>q;
	while(q--)
	{
		int odd=0;
		int t=0;
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			if (a[i]%2==1) odd++;
		}
		if (odd<k || odd%2!=k%2)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for (int i=1;i<=n;i++)
			{
				if (a[i]%2==1 && t!=k-1)
				{
					printf("%d ",i);
					t++;
				}
			}
			printf("%d\n",n);
		}
	}
	return 0;
}