#include <bits/stdc++.h>
using namespace std;

bool canmult(long long a, long long b)
{
    return (a <= 2000000000000000000ll/b);
}

long long fastpow(long long m, long long k)
{
    if(k == 0) return 1ll;
    long long t = 1ll;
    if(k&1) t = m;
    k >>= 1;
    long long x = fastpow(m, k);
    if(!canmult(t, x)) return 2e18;
    t*=x;
    if(!canmult(t, x)) return 2e18;
    return t*x;
}

bool powlt(long long m, long long k, long long n)
{
    return (n >= fastpow(m, k));
}

long long num(long long n, long long p)
{
    long long low = 1ll, hi = 1000000001ll;
    if(p >= 3) hi = 1000001ll;
    if(p >= 5) hi = 10001ll;
    if(p >= 6) hi = 1001ll;
    if(p >= 10) hi = 101ll;
    if(p >= 18) hi = 11ll;
    if(p >= 26) hi = 4ll;
    if(p >= 38) hi = 2ll;
    long long mid = (low + hi + 1ll)/2ll;
    while(low != hi)
    {
        mid = (low + hi + 1ll)/2ll;
        if(powlt(mid, p, n)) low = mid;
        else hi = mid - 1;
    }
    //cout << n << " " << p << " " << hi - 1 << endl;
    return hi - 1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int a[64] = {0, 0, 1, 1, 0, 1, -1, 1, 0, 0, -1, 1, 0, 1, -1, -1, 0, 1, 0, 1, 0, -1, -1, 1, 0, 0, -1, 0, 0, 1, 1, 1, 0, -1, -1, -1, 0, 1, -1, -1, 0, 1, 1, 1, 0, 0, -1, 1, 0, 0, 0, -1, 0, 1, 0, -1, 0, -1, -1, 1, 0, 1, -1, 0};
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        int i;
        long long ans = 0;
        for(i = 2; i < 65; i++)
        {
            if(a[i] != 0 && powlt(2, i, n)) ans += a[i]*num(n, i);
        }
        cout << n - ans - 1ll << endl;
    }
}