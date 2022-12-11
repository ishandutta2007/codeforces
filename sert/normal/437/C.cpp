#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, v1, v2, v[123456], ans;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        ans += min(v[v1], v[v2]);
    }
    cout << ans;
    return 0;
}