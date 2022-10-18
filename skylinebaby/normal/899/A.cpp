#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int aa = 0,bb = 0;
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if (x==1) aa++;
		else bb++;
	}
	if (aa<bb) printf("%d\n",aa);
	else if (aa==bb) printf("%d\n",aa);
	else printf("%d\n",bb+(int)((aa-bb)/3)); 
	return 0;
}