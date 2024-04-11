#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if
#define rep(i,n) for (int i=0;i<n;++i)
int n, m, z, a, b, ans, x[100005];
set<int> H;
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("c.in", "r", stdin);
   // freopen("c.out", "w", stdout);
#endif
    scanf("%d", &n), m = 0, H.insert(2);
    rep(i, n)
    {
        scanf("%d", &z);
        if (H.find(z) == H.end()) H.insert(z), x[m++] = z;
    }
    scanf("%d%d", &a, &b);
    while (a > b)
    {
        int y = 1;
        for (int i = 0; i < m;)
        {
            if (a % x[i] > y && a - a % x[i] >= b) y = a % x[i];
            if (a - a % x[i] < b)
            {
               swap(x[i], x[m - 1]);
               --m;
            }
            else ++i;
        }
        a -= y, ans++;
        //		printf("%d\n",a);
    }
    printf("%d\n", ans);
    return 0;
}