#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[123], b[124], ans;
bool u[123];

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i != j && a[i] == b[j]) u[i] = true;
    }
    for (int i = 0; i < n; i++) ans += !u[i];
    cout << ans;
    return 0;
}