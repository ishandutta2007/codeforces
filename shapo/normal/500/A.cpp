#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< int > used, a;
int n, t;

bool can(int x)
{
    used[x] = true;
    if (x == t) {
        return true;
    }
    if (!used[x + a[x]] && can(x + a[x])) {
        return true;
    }
    return false;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    used.assign(n + 1, 0);
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool ans = can(1);
    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}