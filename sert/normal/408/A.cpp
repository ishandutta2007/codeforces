#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

ll n, ans = 100000000, a[N], t, len, h;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 0; j < a[i]; j++) {
            cin >> h;
            t += 5 * h;
            t += 15;
        }
        ans = min(ans, t);
    }

    cout << ans;

    return 0;
}