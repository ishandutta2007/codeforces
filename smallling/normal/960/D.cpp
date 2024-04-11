#include <bits/stdc++.h>

using namespace std;

long long a[10010], b[10010];

int get(long long x)
{
	int cnt = 0;
	while(x)
	{
		x >>= 1;
		cnt++;
	}
	return cnt;
}

int main()
{
	int Q;
	scanf("%d", &Q);
	while(Q--)
	{
		int opt;
		long long x, K;
		scanf("%d", &opt);
		if(opt == 1)
		{
			scanf("%I64d%I64d", &x, &K);
			int deep = get(x);
			long long nows = 1ll << (deep - 1);
			K %= nows;
			a[deep] += K;
			if(a[deep] < 0)a[deep] += nows;
			if(a[deep] >= nows)a[deep] -= nows;
		}
		else if(opt == 2)
		{
			scanf("%I64d%I64d", &x, &K);
			int deep = get(x);
			long long nows = 1ll << (deep - 1);
			K %= nows;
			b[deep] += K;
			if(b[deep] < 0)b[deep] += nows; 
			if(b[deep] >= nows)b[deep] -= nows;
		}
		else
		{
			scanf("%I64d", &x);
			int deep = get(x);
			long long lastx = x + a[deep];
			if(lastx >= (1ll << deep)) lastx -= 1ll << (deep - 1);
			while(deep)
			{
				printf("%I64d ", x);
				x = lastx;
				x += b[deep];
				if(x >= (1ll << deep)) x -= 1ll << (deep - 1);
				x /= 2;
				lastx = x;
				deep--;
				x -= a[deep];
				if(x < (1ll << (deep - 1))) x += (1ll << (deep - 1));
			}
			puts("");
		}
	}
}