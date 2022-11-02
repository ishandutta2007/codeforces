// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll n, p, q, A[N];
int main()
{
    ll Mn = 1e9 + 10;
    scanf("%lld%lld", &n, &p);
    for (int i = 1; i < N; i ++)
    {
        ll a = n - p * i;
        if (a > 0 && __builtin_popcount(a) <= i && i <= a)
            Mn = min(Mn, (ll)i);
    }
    if (Mn == (ll)(1e9 + 10))
        Mn = -1;
    printf("%lld\n", Mn);
    return 0;
}