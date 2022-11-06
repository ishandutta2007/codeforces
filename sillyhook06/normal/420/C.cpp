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
#define mk make_pair
typedef pair<int, int> pr;

const int N = 600006;
map<pr, int> E;
int n, m, x, y, l, tot, son[N], ed[N], next[N], data[N], d[N], id[N];
LL ans;
bool cmp(const int i, const int j)
{
    return d[i] > d[j];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), m = read();
    rep(i, n)
    {
        x = read(), y = read(), --x, --y, ++d[x], ++d[y];
        if (x > y) swap(x,y);
        map<pr, int>::iterator it = E.find(mk(x, y));
        if (it != E.end()) ++data[it->second << 1], ++data[it->second << 1 | 1];
        else
        {
            E[mk(x, y)] = ++tot;
            l = tot * 2, ed[l] = y, data[l] = 1, next[l] = son[x], son[x] = l;
            ++l, ed[l] = x, data[l] = 1, next[l] = son[y], son[y] = l;
        }
    }
    rep(i, n) id[i] = i;
    sort(id, id + n, cmp);
    int j = n;
    rep(k, n)
    {
        int i = id[k];
        while (j && d[id[j - 1]] + d[i] < m) --j;
        ans += j;
        for (int p = son[i]; p; p = next[p])
        {
            int x = ed[p];
            ans -= d[x] + d[i] >= m;
            ans += d[x] + d[i] - data[p] >= m;
        }
        ans -= d[i] + d[i] >= m;
    }
    printf("%I64d\n", ans / 2);
    return 0;
}