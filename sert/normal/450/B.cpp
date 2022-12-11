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
const ll md = 1e9 + 7;

ll x, y;
ll a, b, a1, b1, n;
ll f[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> a >> b >> n;

    a = (a + md * 34) % md;
    b = (b + md * 34) % md;

    n--;
    n %= 6;

    if (n == 0)
        cout << a;
    else {
        for (int i = 1; i < n; i++) {
            a1 = b;
            b = (b - a + md * 34) % md;
            a = a1;
        }
        cout << b;
    }

    return 0;
}