#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, r, a, b, tot, X[N], V[N], Y[N];
map < int , int > M;
map < int , map < int , int > > C;
int32_t main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &X[i], &Y[i], &V[i]);
        V[i] -= a * Y[i];
    }
    for (int i = 0; i < n; i++)
    {
        tot += M[V[i]] - C[V[i]][Y[i]];
        M[V[i]] ++;
        C[V[i]][Y[i]] ++;
    }
    return !printf("%lld", tot << 1);
}