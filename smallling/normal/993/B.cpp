#include <bits/stdc++.h>

using namespace std;

struct point{
	int x, y;
}a[20];

int n, m;
int cnt[20][2], flag[20];

int main()
{
	int ans1 = 0, ans2 = 0, ans = 0, ansflag = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		if(a[i].x > a[i].y)swap(a[i].x, a[i].y);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, nowcnt = 0, nowx, cnt0 = 0, cnt1 = 0;
		scanf("%d%d", &x, &y);
		flag[x] = flag[y] = 1;
		for(int j = 1; j <= n; j++)
		{
			if(flag[a[j].x] + flag[a[j].y] == 1)
			{
				if(flag[a[j].x])nowx = a[j].x, cnt[j][0]++;
				else nowx = a[j].y, cnt[j][1]++;
				if(x == a[j].x || x == a[j].y)cnt0++;
				else cnt1++;
			}
		}
		if((!cnt0 && cnt1) || (!cnt1 && cnt0))
		{
			ans1++;
			if(ans && ans != nowx)ansflag = 0;
			ans = nowx;
		}
		if(cnt0 && cnt1)
		{
			puts("-1");
			return 0;
		}
		flag[x] = flag[y] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		if((!cnt[i][0] && cnt[i][1]) || (!cnt[i][1] && cnt[i][0]))ans2++;
		if(cnt[i][0] && cnt[i][1])
		{
			puts("-1");
			return 0;
		}
	}
	if(ans && ansflag)
	{
		printf("%d\n", ans);
		return 0;
	}
	if(ans1 > 1 && ans2 > 1)
	{
		puts("0");
		return 0;
	}
	puts("-1");
}