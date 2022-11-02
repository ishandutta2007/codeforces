// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, M[N];
long long A[N];
vector < int > V[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%lld", &A[i]), V[__builtin_ctzll(A[i])].push_back(i);
    int Mx = 0;
    for (int i = 0; i <= 60; i ++)
        if (V[i].size() > V[Mx].size())
            Mx = i;
    printf("%d\n", n - (int)V[Mx].size());
    for (int v : V[Mx])
        M[v] = 1;
    for (int i = 0; i < n; i ++)
        if (!M[i]) printf("%lld ", A[i]);
    return 0;
}