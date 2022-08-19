#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 100005
#define ld double
using namespace std;
int e[maxn];
int st[maxn], fr = 0, ed = 0;
ld sts[maxn];
int n, u;
int main()
{
	scanf("%d%d", &n, &u);
	for(int i = 1; i <= n; i++)
		scanf("%d", &e[i]);
	int pl = 2;
	ld ans = 0;
	bool flag = 0;
	for(int i = 1; i <= n - 2; i++)
	{
		while(pl < n && e[pl + 1] - e[i] <= u) pl++;
		if(pl >= i + 2)
			flag = 1, 
			ans = max(ans, (e[pl] - e[i + 1]) / (ld)(e[pl] - e[i]));
 	}
 	if(flag) printf("%.13lf\n", ans);
 	else printf("-1\n");
	return 0;
}