#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
int n, r, t, p, c, A[N];
long double Mn = 1e9;
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> t;
        long double X = ((long double)r) / t;
        Mn = min(Mn, X);
    }
    cout << setprecision(12) << Mn * p;
    return (0);
}