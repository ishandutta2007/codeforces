// Skywynne
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000006;
int n, m, q, A[N];
ll X[N], Y[N];
ll ax, ay, bx, by, xs, ys, t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> X[0] >> Y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    while (true)
    {
        if ((long double)X[n] * ax + bx > (ll)(1e18))
            break;
        if ((long double)Y[n] * ay + by > (ll)(1e18))
            break;
        X[n + 1] = X[n] * ax + bx;
        Y[n + 1] = Y[n] * ay + by;
        n ++;
    }
    int Mx = 0;
    for (int i = 0; i <= n; i ++)
    {
        ll tt = t - abs(xs - X[i]) - abs(ys - Y[i]);
        if (tt < 0)
            continue;
        for (int j = 0; j <= i; j ++)
            for (int k = i; k <= n; k ++)
            {
                ll need1 = abs(X[k] - X[i]) + abs(Y[k] - Y[i]);
                ll need2 = abs(X[j] - X[i]) + abs(Y[j] - Y[i]);
                if (need1 + need2 + min(need1, need2) <= tt)
                    Mx = max(Mx, k - j + 1);
            }
    }
    printf("%d\n", Mx);
    return 0;
}