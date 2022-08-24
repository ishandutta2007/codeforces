#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int par[55];

int cfind (int x)
{
    if (par[x] == x) return x;
    return par[x] = cfind (par[x]);
}

bool uni (int a, int b)
{
    a = cfind (a);
    b = cfind (b);
    if (a == b) return false;
    par[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 55; i++)
        par[i] = i;

    int N, M;
    cin >> N >> M;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        if (uni (x, y))
            ans++;
    }
    cout << (1LL << ans) << "\n";
}