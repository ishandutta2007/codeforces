// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int n, g, m;
long long s;
int main()
{
    scanf("%d", &n);
    vector < int > A(n);
    for (int &a : A)
        scanf("%d", &a), m = max(m, a), s += a;
    for (int a : A)
        g = __gcd(g, m - a);
    return !printf("%lld %d\n", (m * 1LL * n - s) / g, g);
}