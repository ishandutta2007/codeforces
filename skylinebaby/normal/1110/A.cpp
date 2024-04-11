#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int sum = 0;
	for(int i = 0;i<k-1;i++)
	{
		int x;
		scanf("%d",&x);
		sum += x;
	}
	if(n%2==0)
	{
		int x;
		scanf("%d",&x);
		if(x%2) printf("odd\n");
		else printf("even\n");
		return 0;
	}
	int x;
	scanf("%d",&x);
	sum += x;
		if(sum%2) printf("odd\n");
		else printf("even\n");
	return 0;
}