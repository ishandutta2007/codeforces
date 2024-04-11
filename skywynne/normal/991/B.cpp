#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i], c += A[i];
    m = ceil(4.5 * n);
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        if (c >= m)
            return !printf("%d", t);
        c += 5 - A[i];
        t ++;
    }
    return !printf("%d", t);
    return (0);
}