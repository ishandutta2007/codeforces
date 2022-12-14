#include <stdio.h>
#include <algorithm>
int a[500005];
int n;
int k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	a[n] = 0;
	std::sort(a, a + n);
	std::reverse(a, a + n);
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	if(sum <= (long long)k)
	{
		long long ln = n;
		long long ans = sum % ln;
		if(ans >= 1) ans = 1;
		printf("%I64d\n", ans);
		return 0;
	}
	long long tmp = k;
	long long r = 0;
	long long h = a[0];
	long long nxt;
	while(tmp)
	{
		while(r + 1 < n && h == a[r + 1]) r++;
		nxt = a[r + 1];
		if((r + 1) * (h - nxt) <= tmp)
		{
			tmp -= (r + 1) * (h - nxt);
			h = nxt;
			if(tmp == 0)
			{
				for(int i = 0; i <= r; i++)
					a[i] = h;
			}
		}
		else
		{
			long long l = r + 1;
			long long cha = tmp / l;
			long long left = tmp % l;
			for(int i = 0; i < l; i++)
				a[i] = h - cha;
			for(int i = 0; i < left; i++)
				a[i]--;
			tmp = 0;
		}
	}
	//for(int i = 0; i < n; i++)
	//	printf("%d ", a[i]);
	std::sort(a,a + n);
	tmp = k;
	r = 0;
	h = a[0];
	while(tmp)
	{
		while(r + 1 < n && a[r + 1] == h) r++;
		if(r == n - 1)
			break;
		nxt = a[r + 1];
		if(tmp >= (r + 1) * (nxt - h))
		{
			tmp -= (r + 1) * (nxt - h);
			h = nxt;
			if(tmp == 0)
			{
				for(int i = 0; i <= r; i++)
					a[i] = h;
			}
		}
		else
		{
			long long l = r + 1;
			long long add = tmp / l;
			long long left = tmp % l;
			for(int i = 0; i < l; i++)
				a[i] = h + add;
			for(int i = 0; i < left; i++)
				a[i]++;
			tmp = 0;
		}
	}
	if(tmp > 0)
	{
		long long ln = n;
		long long ans = tmp % ln;
		if(ans >= 1) ans = 1;
		printf("%I64d\n", ans);
		return 0;
	}
	else
	{
		long long maxx = a[0];
		long long minn = a[0];
		for(int i = 0; i < n; i++)
			if(a[i] > maxx) maxx = a[i];
		for(int i = 0; i < n; i++)
			if(a[i] < minn) minn = a[i];
		long long ans = maxx - minn;
		printf("%I64d\n", ans);
		return 0;
	}
}