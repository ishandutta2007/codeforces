#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define M 200005
#define N 1000005
#define pb push_back
#define F first
#define S second
#define ll long long
#define ls (k << 1)
#define rs (k << 1 | 1)
#define int long long
int n, m, K, ans, dta;
std::map<ll, ll> mp, f;
struct node{
    int l, r, c, p;
    friend bool operator < (node x, node y)
    {
        return x.p < y.p;
    }
}s[M];
struct tree{
    int l, r, sum, max;
    bool fl;
}t[N << 2];
inline void build (int k, int x, int y)
{
    t[k].l = x; t[k].r = y;
    if (x == y) return;
    int mid = x + y >> 1;
    build(ls, x, mid); build(rs, mid + 1, y);
}
inline void pushdown (int k)
{
    if (!t[ls].fl) t[ls].sum += t[k].sum;
    if (!t[rs].fl) t[rs].sum += t[k].sum;
    t[k].max += t[k].sum;
    t[k].sum = 0;
}
inline int add (int k, int i)
{
    int ret = 0;
    if (t[k].l < s[i].l || s[i].r < t[k].r)
    {
        int mid = t[k].l + t[k].r >> 1;
        pushdown(k);
        if (mid < s[i].l)
            ret = add(rs, i);
        else
        {
            if (s[i].r <= mid)
                ret = add(ls, i);
            else
                ret = add(ls, i) + add(rs, i);
        }
    }
    else
    {
        if (t[k].fl) return 0;
        if (t[k].sum == K) {t[k].fl = 1; return 0;}
        if (t[k].l == t[k].r)
        {
            if (t[k].sum + s[i].c > K)
            {
                ret = (K - t[k].sum) * s[i].p;
                t[k].sum = K;
                t[k].fl = 1;
            }
            else
            {
                t[k].sum += s[i].c;
                ret = s[i].c * s[i].p;
            }
            return ret;
        }
        if (t[k].max + t[k].sum + s[i].c > K)
        {
            pushdown(k);
            ret = add(ls, i) + add(rs, i);
        }
        else
        {
            if (t[k].sum + s[i].c <= K)
            {
                t[k].sum += s[i].c;
                ret = s[i].p * s[i].c * (t[k].r - t[k].l + 1);
            }
            else
            {
                ret = (K - t[k].sum) * s[i].p * (t[k].r - t[k].l + 1);
                t[k].sum = K;
                t[k].fl = 1;
            }
        }
    }
    if (t[ls].l && t[rs].l)
    {
        t[k].fl = t[ls].fl && t[rs].fl;
        t[k].max = std::max(t[ls].max + t[ls].sum, t[rs].max + t[rs].sum);
    }
    return ret;
}
main ()
{
    scanf("%lld %lld %lld", &n, &K, &m);
    fo (i, 1, m)
        scanf("%lld %lld %lld %lld", &s[i].l, &s[i].r, &s[i].c, &s[i].p);
    std::sort(s + 1, s + m + 1);
    build(1, 1, n);
    fo (i, 1, m)
    {
        ans += add(1, i);
    //    printf("%d\n", ans);
    //    fo (j, 1, 9)
    //        printf("k = %d l = %d r = %d sum = %d max = %d flag = %d \n", j, t[j].l, t[j].r, t[j].sum, t[j].max, t[j].fl);
    }
    printf("%lld", ans);
    return 0;
}