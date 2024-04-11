#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
int n,k,a[MAXN];
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		printf("7");
		for(int i=0;i<n/2-1;i++)
			printf("1");
	}
	else
	{
		for(int i=0;i<n/2;i++)
			printf("1");
	}
	printf("\n");
	return 0;
}