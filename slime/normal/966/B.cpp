#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 300005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
struct th
{
	int num, pl;
	bool operator < (const th &a)const
	{
		return num < a.num;
	}
}p[maxn];
int dv(int a, int b)
{
	int ans = a / b;
	if(a % b) ans++;
	return ans;
}
int main()
{
	int x[2], n;
	scanf("%d%d%d", &n, &x[0], &x[1]);
	for(int i = 1; i <= n; i++)
		p[i].pl = i, scanf("%d", &p[i].num);
	sort(p + 1, p + n + 1);
	bool flag = 0;
	for(int i = 0; i < 2; i++)
	{
		if(flag) break;
		int lst = n + 1;
		for(int j = n; j >= 1; j--)
		{
			if(flag) break;
			int ndv = dv(x[i], p[j].num);
			if(ndv + lst <= n - j + 1)
			{
				flag = 1;
				printf("Yes\n");
				if(!i)
				{
					printf("%d %d\n", ndv, n - j + 1 - ndv);
					for(int k = j; k < j + ndv; k++)
						printf("%d ", p[k].pl);
					printf("\n");
					for(int k = j + ndv; k <= n; k++)
						printf("%d ", p[k].pl);
					printf("\n");
				}
				else
				{
					printf("%d %d\n",n - j + 1 - ndv, ndv);	
					for(int k = j + ndv; k <= n; k++)
						printf("%d ", p[k].pl);
					printf("\n");
					for(int k = j; k < j + ndv; k++)
						printf("%d ", p[k].pl);
					printf("\n");
				}
			}
			int ns = dv(x[!i], p[j].num);
			if(ns <= n - j + 1)
				lst = min(lst, ns);
		}
	}
	if(!flag) printf("No\n");
	return 0;
}