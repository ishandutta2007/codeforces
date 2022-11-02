#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int q, r, t, a, b, tot, d, C[20], D[30][30];
vector < int > A, B;
void get(int l = 0, int w = 0)
{
    int ret = 0;
    if (l == A.size())
    {
        int s = 0, c = 1;
        for (auto X : B)
            s += X;
        for (auto X : B)
            c *= D[X][s], s -= X;
        tot += c;
        return ;
    }
    int tt = 1;
    if (l == 0 && w == 1) tt = 0;
    for (int i = tt; i <= A[l]; i++)
    {
        B.pb(i);get(l + 1);
        B.pop_back();
    }
}
int Solve(int n)
{
    int C[10], _n = n;
    memset(C, 0, sizeof(C)); A.clear();
    while (_n)
        C[_n % 10] ++, _n /= 10;
    for (int i = 0; i <= 9; i++)
        if (C[i])
            A.pb(C[i]);
    get();
    int ret = tot; tot = 0;
    if (!C[0])
        return (ret);
    C[0] --;
    A.clear();
    A.pb(C[0]);
    for (int i = 1; i <= 9; i++)
        if (C[i])
            A.pb(C[i]);
    get(0, 1);
    ret -= tot; tot = 0;
    return (ret);
}
int32_t main()
{
    int n;
    for (int i = 0; i < 20; i++)
        D[0][i] = D[i][i] = 1;
    for (int i = 0; i < 20; i++)
        for (int j = 1; j < i; j++)
            D[j][i] = (D[j][i - 1] + D[j - 1][i - 1]);
    scanf("%lld", &n);
    printf("%lld\n", Solve(n));
    return (0);
}