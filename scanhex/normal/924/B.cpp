#include <bits/stdc++.h>

using namespace std;
typedef long double db;

vector<int> arr;
db ans = -1;
int u;

void solve(int l, int r, int optl, int optr)
{
    if (l == r)
        return;
    int m = (l + r) / 2;
    db a = -1, opti = -1;
    for (int i = optl; i <= optr; ++i)
    {
        if (i + 1 >= m)
            break;
        if (arr[m] - arr[i] > u)
            continue;
        db kek = arr[m] - arr[i + 1];
        kek /= arr[m] - arr[i];
        if (kek > a)
            a = kek, opti = i;
    }
    ans = max(ans, a);
    if (opti == -1)
        opti = m - 1;
    solve(l, m, optl, opti);
    solve(m + 1, r, opti, optr);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> u;
    arr.resize(n);
    for (auto& x : arr)
        cin >> x;
    solve(0, n, 0, n - 1);
    cout.precision(30);
    cout << ans << '\n';
}