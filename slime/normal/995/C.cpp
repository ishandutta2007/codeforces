#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long 
using namespace std;
ll sqr(ll a)
{
	return a * a;
}
struct th
{
	int x, y, id;
}p[maxn];
int tp[maxn];
int ans[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
	while(1)
	{
		random_shuffle(p + 1, p + n + 1);
		ll nx = 0, ny = 0;
	
		for(int i = 1; i <= n; i++)
		{		
			ll ns = sqr(maxn) * 1000000;
			tp[i] = -1;
			for(int j = -1; j <= 1; j++)
			{
				if(j == 0) continue;
				ll ex = nx + p[i].x * j, ey = ny + p[i].y * j;
				ll nans = sqr(ex) + sqr(ey);
				if(nans < ns) ns = nans, tp[i] = j;
			}
			nx += p[i].x * tp[i], ny += p[i].y * tp[i];
		}
		if(sqr(nx) + sqr(ny) <= sqr(1500000))
		{
			for(int i = 1; i <= n; i++)
				ans[p[i].id] = tp[i];
			for(int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
		//	cout<<nx<<" "<<ny<<endl;
			printf("\n");
			break;
		}
	}
	return 0;
}