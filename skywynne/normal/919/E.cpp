#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long p, x, r, t, k, s, c, res, A[N];
vector < long long > T[N];
long long Power(long long a, long long b)
{
    if (b == 0)
        return (1);
    long long tt = Power(a, b / 2);
    tt = tt * tt % p;
    if (b & 1)
        tt = tt * a % p;
    return (tt);
}
int main()
{
    long long a, b;
    cin >> a >> b >> p >> x;
    A[0] = 1;
    for (int i = 1; i < p; i++)
        A[i] = (A[i - 1] * a) % p, T[A[i]].push_back(i);
    c = p * (p - 1);
    for (int i = 1; i < p; i++)
    {
        r = (b * Power(i, p - 2)) % p;
        for (auto X : T[r])
        {
            t = X;
            if (t % p >= i)
                t += (t - i) * (p - 1);
            else
                t += (p - i + t) * (p - 1);
            if (t > x)
                continue;
            res += (x - t) / c + 1;
        }
    }
    cout << res;
    return (0);
}