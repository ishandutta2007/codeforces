#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int ans=min(max(a*2,b),max(b*2,a));
		printf("%d\n",ans*ans);
	}
	return 0;
}