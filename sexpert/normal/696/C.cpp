#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long PMOD = MOD - 1;

long long modpow(long long a, long long b)
{
    b = ((b % PMOD) + PMOD) % PMOD;
    if(b == 0)
        return 1;
    if(b % 2)
        return (a * modpow(a, b - 1))%MOD;
    long long p = modpow(a, b/2);
    return (p * p)%MOD;
}

long long inv(long long n)
{
    return modpow(n, MOD - 2);
}

int main()
{
    long long n = 1;
    bool even = false;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        long long a;
        cin >> a;
        if(a % 2 == 0)
            even = true;
        a %= PMOD;
        n = (n * a)%PMOD;
    }
    long long x, y;
    if(even)
    {
        x = modpow(2, n - 1);
        x = (x + 1)%MOD;
        x = (x * inv(3))%MOD;
        y = modpow(2, n - 1);
    }
    else
    {
        x = modpow(2, n - 1);
        x = (x + MOD - 1)%MOD;
        x = (x * inv(3))%MOD;
        y = modpow(2, n - 1);
    }
    cout << x << "/" << y << endl;
}