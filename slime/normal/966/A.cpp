#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 100005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
int n, m;
int l[maxn], e[maxn];
int v;
int main()
{
	int ls, es;
	scanf("%d%d%d%d%d", &n, &m, &ls, &es, &v);
	for(int i = 0; i < ls; i++)
		scanf("%d", &l[i]);
	for(int i = 0; i < es; i++)
		scanf("%d", &e[i]);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = 2000000000;
		if(x1 == x2)
			ans = abs(y1 - y2);
		else
		{
			swap(x1, y1), swap(x2, y2);
			if(ls && l[0] <= x1)
			{
				int L = 0, R = ls - 1;
				while(L < R)
				{
					int mid = (L + R) >> 1;
					if(l[mid + 1] <= x1) L = mid + 1;
					else R = mid;
				}
				int nans = abs(y2 - y1) + abs(x1 - l[L]) + abs(x2 - l[L]);
				ans = min(ans, nans);
			}
			if(ls && l[ls - 1] >= x1)
			{
				int L = 0, R = ls - 1;
				while(L < R)
				{
					int mid = (L + R) >> 1;
					if(l[mid] >= x1) R = mid;
					else L = mid + 1;
				}
				int nans = abs(y2 - y1) + abs(x1 - l[L]) + abs(x2 - l[L]);
				ans = min(ans, nans);
			}
			int ne = abs(y2 - y1);
			if(ne % v) ne = ne / v + 1;
			else ne = ne / v;
			if(es && e[0] <= x1)
			{
				int L = 0, R = es - 1;
				while(L < R)
				{
					int mid = (L + R) >> 1;
					if(e[mid + 1] <= x1) L = mid + 1;
					else R = mid;
				}
				int nans = ne + abs(x1 - e[L]) + abs(x2 - e[L]);
				ans = min(ans, nans);
			}
			if(es && e[es - 1] >= x1)
			{
				int L = 0, R = es - 1;
				while(L < R)
				{
					int mid = (L + R) >> 1;
					if(e[mid] >= x1) R = mid;
					else L = mid + 1;
				}
				int nans = ne + abs(x1 - e[L]) + abs(x2 - e[L]);
			//	cout<<nans<<endl;
				ans = min(ans, nans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}