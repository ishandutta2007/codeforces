#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, s, i, x, y;
pair <ll, ll> a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> a[i].second;
        a[i].first = x * x + y * y;
    }

    sort(a, a + n);

    for (i = 0; s < 1000000 && i < n; i++) s += a[i].second;

    if (s < 1000000) {
        cout << -1;
        return 0;
    }

    cout.precision(10);
    cout << fixed << sqrtl(a[i - 1].first);

    return 0;
}