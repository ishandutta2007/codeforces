#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n, tot = 1;
map < int , int > L, R;
set < int > S;
int main()
{
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++)
    {
        scanf("%d", &a);
        if (!L.count(a))
            L[a] = i;
        R[a] = i;
        S.insert(i);
    }
    for (auto X : L)
    {
        auto l = S.upper_bound(X.second);
        auto r = S.upper_bound(R[X.first]);
        S.erase(l, r);
    }
    for (int i = 0; i < (int)S.size() - 1; i++)
        tot = tot * 2 % Mod;
    return !printf("%d", tot);
}