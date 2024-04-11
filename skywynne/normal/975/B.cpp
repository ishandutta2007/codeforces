#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N], B[N];
int32_t main()
{
    for (int i = 0; i < 14; i++)
        cin >> A[i];
    int Mx = -1;
    for (int i = 0; i < 14; i++)
        if (A[i] > 0)
        {
            for (int j = 0; j < 14; j++)
                B[j] = A[j];
            B[i] = 0;
            for (int j = 1; j <= A[i] % 14; j++)
                B[(i + j) % 14] += A[i] / 14 + 1;
            for (int j = A[i] % 14 + 1; j <= 14; j++)
                B[(i + j) % 14] += A[i] / 14;
            int ret = 0;
            for (int j = 0; j < 14; j++)
                if (B[j] % 2 == 0)
                    ret += B[j];
            Mx = max(Mx, ret);
        }
    cout << Mx;
    return (0);
}