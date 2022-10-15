#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int l[MAXN],r[MAXN];
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&r[i]);
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			if(r[i]<tt) 
			{
				printf("0 ");
				continue;
			}
			else
			{
				tt=max(tt,l[i])+1;
				printf("%d ",tt-1);
			}
		}
		printf("\n");
	}
	return 0;
}