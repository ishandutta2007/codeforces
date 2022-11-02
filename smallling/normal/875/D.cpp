#include <bits/stdc++.h>

#define N 200010
#define inf 0x3f3f3f3f

using namespace std;

int a[N], b[N], L[N], R[N], ansl[N], ansr[N];
pair<int, int> sta[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int r = n + 1;
	sta[--r] = make_pair(inf, 0);
	for(int i = 1; i <= n; i++)
	{
		int k = lower_bound(sta + r, sta + 1 + n, make_pair(a[i], inf)) - sta;
		while(r <= n && sta[r].first <= a[i])r++;
		L[i] = sta[k].second;
		sta[--r] = make_pair(a[i], i);
	}
	r = n + 1;
	sta[--r] = make_pair(inf, n + 1);
	for(int i = n; i; i--)
	{
		int k = lower_bound(sta + r, sta + 1 + n, make_pair(a[i], 0)) - sta;
		while(r <= n && sta[r].first <= a[i])r++;
		R[i] = sta[k].second;
		sta[--r] = make_pair(a[i], i);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ansl[i] = L[i], ansr[i] = R[i];
	for(int x = 0; x < 31; x++)
	{
		*b = 0;
		b[++*b] = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] & (1 << x))
			{
				b[++*b] = i;
			}
		b[++*b] = n + 1;
		for(int i = 1; i <= n; i++)
			if(!(a[i] & (1 << x)))
			{
				int k = lower_bound(b + 1, b + 1 + *b, i) - b;
				ansr[i] = min(ansr[i], b[k]);
				ansl[i] = max(ansl[i], b[k - 1]);
			}
	}
	for(int i = 1; i <= n; i++)
	{
		ans += 1ll * (i - L[i]) * (R[i] - i) - 1ll * (i - ansl[i]) * (ansr[i] - i);
	}
	printf("%I64d\n", ans); 
}