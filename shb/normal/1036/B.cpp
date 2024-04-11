#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		LL N,M,K;
		scanf("%lld%lld%lld",&N,&M,&K);
		if (N < M) swap(N,M);
		if (K < N)
		{
			puts("-1");
			continue;
		}
		if ((N - M) % 2 == 0)
		{
			if ((K - N) % 2 != 0)
				K-=2;
		}
		else
		{
			K--;
		}
		printf("%lld\n",K);
	}
}