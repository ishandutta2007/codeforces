#include<bits/stdc++.h>
#define int long long
using namespace std;
bool iden[100001];
vector<int> prime;
void pp()
{
	for (int i = 2;i<=100000;i++)
	{
		if (!iden[i]) prime.push_back(i);
		for (int j = 0; i*prime[j]<=100000;j++)
		{
			iden[i*prime[j]]=true;
			if (i%prime[j]==0) break;
		}
	}
}
main()
{
	int p,y;
	scanf("%lld %lld",&p,&y);
	pp();
	if (p*p>y)
	{
		for(int i = y;i>p;i--)
		{
			int flag = 0;
			for(int j = 0;prime[j]*prime[j]<=i;j++)
			{
				if (i%prime[j]==0) 
				{
					flag = 1;
					break;
				}
			}
			if (flag==0)
			{
				printf("%lld\n",i);
				return 0;
			}
		}
		printf("-1\n");
		return 0;
	}
	else 
	{
		int need = 0;
		while(prime[need]<=p)
		{
			need++;
		}
		need--;
		for(int i = y;i>=p;i--)
		{
			int flag = 0;
			for(int j = 0;j<=need;j++)
			{
				if (i%prime[j]==0) 
				{
					flag = 1;
					break;
				}
			}
			if (flag==0)
			{
				printf("%lld\n",i);
				return 0;
			}
		}		
	}
	return 0;
}