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
#define rep(i,n) for (int i=1;i<=n;++i)

#define tree int t,int l,int r
#define left t<<1,l,mid
#define right t<<1|1,mid+1,r
#define M int mid=l+r>>1
#define mk make_pair
typedef pair<int, int> pr;
const int N = 100005;
int n, m, type, l, r;
pr a[N * 4];
LL s[N * 4];
void upd(int t)
{
    int L = t << 1, R = L | 1;
    a[t] = max(a[L], a[R]), s[t] = s[L] + s[R];
}
void build(tree)
{
    if (l == r)
    {
        s[t] = read(), a[t] = mk(s[t], l);
        return;
    }
    M;
    build(left), build(right), upd(t);
}
LL query(tree, int ll, int rr)
{
    if (l == ll && r == rr) return s[t];
    M;
    if (rr <= mid) return query(left, ll, rr);
    if (ll > mid) return query(right, ll, rr);
    return query(left, ll, mid) + query(right, mid + 1, rr);
}
void modify(tree, int x, int y)
{
    if (l == r)
    {
        a[t] = mk(y, x), s[t] = y;
        return;
    }
    M;
    if (x <= mid) modify(left, x, y);
    else modify(right, x, y);
    upd(t);
}
pr get(tree, int ll, int rr)
{
    if (l == ll && r == rr) return a[t];
    M;
    if (rr <= mid) return get(left, ll, rr);
    if (ll > mid) return get(right, ll, rr);
    return max(get(left, ll, mid), get(right, mid + 1, rr));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), m = read();
    build(1, 1, n);
    while (m--)
    {
        type = read(), l = read(), r = read();
        if (type == 1) printf("%I64d\n", query(1, 1, n, l, r));
        else if (type == 3) modify(1, 1, n, l, r);
        else
        {
            int p = read(), y;
            pr x;
            do
            {
                x = get(1, 1, n, l, r), y = x.first;
                if (y >= p) modify(1, 1, n, x.second, y % p);
            }
            while (y >= p);
        }
    }
    return 0;
}