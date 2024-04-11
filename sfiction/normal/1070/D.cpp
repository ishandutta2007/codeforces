#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

char dp[5010][501];

int main()
{
	int n,k;

	long long sum = 0;

	scanf("%d%d",&n,&k);

	int tmp;
	int left = 0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);

		if (left>0)
		{
			sum++;
			tmp-=k-left;
			left = 0;
		}
		if (tmp>0)
		{
			sum+=tmp/k;
			left = tmp%k;
		}
	}
	if (left>0) sum++;
	cout<<sum<<endl;
}