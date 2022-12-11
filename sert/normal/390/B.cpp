#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

ll n, a[100500], b[100500], ans;
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        if (a[i] * 2 < b[i] || b[i] == 1)
            ans--;
        else
            ans += (b[i] / 2) * (b[i] - b[i] / 2);

    cout << ans;

    return 0;
}