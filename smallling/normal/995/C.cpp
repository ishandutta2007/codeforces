#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct point{
	int x, y, id;
}a[N];

int ans[N];

long long dis(int x, int y)
{
	return 1ll * x * x + 1ll * y * y;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	while(1)
	{
		random_shuffle(a + 1, a + 1 + n);
		point now = (point){0, 0};
		for(int i = 1; i <= n; i++)
		{
			if(dis(now.x + a[i].x, now.y + a[i].y) < dis(now.x - a[i].x, now.y - a[i].y))
			{
				now.x += a[i].x;
				now.y += a[i].y;
				ans[a[i].id] = 1;
			}
			else
			{
				now.x -= a[i].x;
				now.y -= a[i].y;
				ans[a[i].id] = -1;
			}
		}
		if(dis(now.x, now.y) <= 2250000000000ll)
		{
			for(int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			return 0;
		}
	}
}