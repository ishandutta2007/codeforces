#include<bits/stdc++.h>
using namespace std;
int n, k, m, p, r, t, c, s, Mx;
long long A[50];
int main()
{
    cin >> n >> k >> m;
    if (m == 0)
    {
        cout << 0;
        return (0);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
        s += A[i];
    }
    sort(A, A + k);
    for (int i = 0; i <= n; i++)
    {
        p = m;
        p -= s * i;
        if (p < 0)
            break;
        c = (k + 1) * i;
        t = r = 0;
        if (i == n)
            t = k + 1;
        while (p - A[t] >= 0 && t < k)
        {
            p -= A[t];
            c ++;
            r ++;
            if (n - i - r == 0)
            {
                r = 0;
                t ++;
            }
        }
        Mx = max(Mx, c);
    }
    cout << Mx;
    return (0);
}