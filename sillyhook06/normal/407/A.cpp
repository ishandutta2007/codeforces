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
    int x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if
#define rep(i,n) for (int i=0;i<n;++i)

int a, b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    a = read(), b = read();
    if (a > b) swap(a, b);
    for (int i = 1 - a; i < a; ++i) if (i)
    {
        int j = a * a - i * i, k = int(sqrt(j));
        if (k * k == j && b * k % a == 0 && b * i % a == 0 && i != b * k / a && k != - b * i / a)
        {
            puts("YES");
            printf("%d %d\n", i, k);
            printf("%d %d\n", 0, 0);
            printf("%d %d\n", b * k / a, - b * i / a);
            return 0;
        }
    }
    puts("NO");
    return 0;
}