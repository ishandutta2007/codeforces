#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, r, t, a, b, c, d, A[N], M[N];
int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < r; i++)
        scanf("%d", &t), M[t] = 1;
    for (int i = 0; i < n; i++)
        if (M[A[i]])
            printf("%d ", A[i]);
    return (0);
}