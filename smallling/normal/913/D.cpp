#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

struct lhy{
	int a, t, id;
	bool operator < (const lhy &b) const
	{
		return t < b.t;
	}
}a[N];

int Ans[N], nowans[N];

int check(int x, int n, int T)
{
	nowans[0] = 0;
	for(int i = 1; i <= n; i++)
		if(a[i].a >= x && a[i].t <= T)
		{
			T -= a[i].t;
			nowans[++nowans[0]] = a[i].id;
			if(nowans[0] == x)break;
		}
	if(nowans[0] < x)return 0;
	Ans[0] = nowans[0];
	for(int i = 1; i <= Ans[0]; i++)
		Ans[i] = nowans[i];
	return 1;
}

int main()
{
	int n, T;
	scanf("%d%d", &n, &T);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].a, &a[i].t), a[i].id = i;
	sort(a + 1, a + 1 + n);
	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid, n, T))ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	printf("%d\n", Ans[0]);
	for(int i = 1; i <= Ans[0]; i++)
		printf("%d%c", Ans[i], (i == Ans[0] ? '\n' : ' '));
}