#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 1e5 + 10;
int n, Mn = 1e9, Mx, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), Mx = max(Mx, abs(A[i]) + 1), A[i] += A[i - 1];
    Mn = Mx * Mx + 1;
    for (int i = 1; i <= n; i++)
       for (int j = i + 1; j <= min(n, i + 2000) && (i - j) * (i - j) <= Mn; j++)
            Mn = min(1ll * Mn, 1ll * (i - j) * (i - j) + 1ll * (A[j] - A[i]) * (A[j] - A[i]));
    return !printf("%d", Mn);
}