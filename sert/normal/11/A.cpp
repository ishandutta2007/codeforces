#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

ll n, d, t, ans, pr, kol;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> d >> t;
    for (int i = 1; i < n; i++) {
        pr = t;
        cin >> t;
        if (t <= pr) {
            kol = (pr - t) / d + 1;
            ans += kol;
            t += kol * d;
        }
    }

    cout << ans;

    return 0;
}