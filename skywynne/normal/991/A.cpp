#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
int main()
{
    cin >> a >> b >> c >> n;
    if (c > a || c > b)
        return puts("-1");
    if (a >= n || b >= n || c >= n)
        return puts("-1");
    if (a + b - c >= n)
        return puts("-1");
    printf("%d", n - (a + b - c));
    return (0);
}