#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
long long n, m, ss, ff, r, t, a, b, c, p, s, f, Mx = -1e9, A[N], P[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> s >> f; s --; f --;
    for (int i = 0; i < n; i++)
    {
        ss = (s - i + n) % n;
        ff = (f - i + n) % n;
        if (ss < ff)
        {
            P[ss] += A[i];
            P[ff] -= A[i];
        }
        else
        {
            P[ss] += A[i];
            P[0] += A[i];
            P[ff] -= A[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            P[i] += P[i - 1];
        if (Mx < P[i])
            Mx = P[i], c = i;
    }
    cout << c + 1;
    return (0);
}