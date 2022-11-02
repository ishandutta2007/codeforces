#include<bits/stdc++.h>
using namespace std;
int n, m, k = 1, c, p, t, r, A[5010], P[5010], G[5010];
map < int , int > M;
int GCD(int a, int b)
{
    if (b == 0)
    {
        return (a);
    }
    return (GCD(b, a % b));
}
int main()
{
    cin >> n >> m;
    //n = 5000;
    //m = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        //A[i] = 1e9 + 7;
        G[i] = A[i];
        if (i > 1)
        {
            G[i] = GCD(G[i - 1], G[i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> P[i];
        //P[i] = 3;
    }
    for (int i = n; i >= 1; i--)
    {
        r = k;
        p = t = 0;
        //cout << i << " ::::::\n";
        for (int j = 1; j <= m; j++)
        {
            while ((G[i] / r) % P[j] == 0)
            {
                //cout << G[i] << " " << r << "\n";
                r *= P[j];
                p ++;
            }
        }
        r = G[i] / r;
        for (int j = 2; j <= sqrt(r);)
        {
            if (p <= t)
            {
                break;
            }
            if (r % j != 0)
            {
                j ++;
                continue;
            }
            t ++;
            r /= j;
        }
        if (r != 1)
        {
            t ++;
        }
        if (p > t)
        {
            //cout << i << " : ";
            k = G[i];
        }
        A[i] /= k;
        for (int j = 1; j <= m; j++)
        {
            while (A[i] % P[j] == 0)
            {
                //cout << 1;
                c --;
                A[i] /= P[j];
            }
        }
        //cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << A[i] << " ";
        if (M.count(A[i]) != 0)
        {
            c += M[A[i]];
            continue;
        }
        t = A[i];
        p = 0;
        for (int j = 2; j <= sqrt(A[i]);)
        {
            if (A[i] % j != 0)
            {
                j ++;
                continue;
            }
            A[i] /= j;
            p ++;
            c ++;
        }
        if (A[i] != 1)
        {
            p ++;
            c ++;
        }
        M[t] = p;
    }
    cout << c;
    return (0);
}