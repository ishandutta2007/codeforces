// I'm back ...
#include<bits/stdc++.h>
using namespace std;
long long n, k, l, r, st;
map < pair < long long , long long > , long long > M[2];
long long Count(long long len, long long t, bool w)
{
    if (M[w].count({len, t}))
        return (M[w][{len, t}]);
    if (t > len)
        return (M[w][{len, t}] = 0);
    if (len == t)
        return (M[w][{len, t}] = 1);
    return (M[w][{len, t}] = Count(len / 2, t, w) + Count((len - 1) / 2, t, w) + w);
}
long long get(long long len, long long t)
{
    return (Count(len, t, 0) + Count(len, t + 1, 0));
}
int main()
{
    scanf("%I64d%I64d", &n, &k);
    if (k == 1)
        return !printf("1");
    if (k == 2)
        return !printf("%I64d", n);
    n -= 2; k -= 2; l = 1; r = n;
    while (r - l > 1)
    {
        if (k > Count(n, (l + r) / 2 * 2 - 1, 1))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    st = l * 2 - 1; l = 1; r = n; k -= Count(n, st + 2, 1);
    while (get(r - l + 1, st) && !(st == 1 && r - l <= 1))
    {
        if (k <= get((l + r) / 2 - l, st))
            r = (l + r) / 2 - 1;
        else
            k -= get((l + r) / 2 - l, st), l = (l + r) / 2 + 1;
    }
    if (st == 1 && r - l <= 1)
        l += k;
    return !printf("%I64d", l);
}