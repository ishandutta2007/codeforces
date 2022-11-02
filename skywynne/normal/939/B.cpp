#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
long long n, m, Mn = 2e18, r, k, t, a, b, c, p, A[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> A[i];
        if (Mn > n % A[i])
        {
            Mn = n % A[i];
            c = i;
        }
    }
    cout << c << " " << n / A[c];
    return (0);
}