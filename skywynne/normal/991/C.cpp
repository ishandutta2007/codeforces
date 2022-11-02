#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, c, d, A[N];
int Solve(int p)
{
    int a = n, t = 0;
    while (a >= 0)
    {
        if (a < p)
        {
            t += a;
            a = 0;
            break;
        }
        t += p;
        a -= p;
        a -= (int)(a / 10);
    }
    return (t);
}
int32_t main()
{
    int l = 0, r = 2e18, m;
    cin >> n;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (Solve(m) * 2 >= n)
            r = m;
        else
            l = m;
    }
    cout << r;
    return (0);
}