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
#include <stack>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

ll l = -1, r = -1, n, a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; b[i] = a[i++]) cin >> a[i];
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    if (b[i] != a[i]) {
        l = i;
        break;
    }

    if (l == -1) {
        cout << "yes\n1 1\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        if (b[i] != a[i])
            r = i;
    reverse(a + l, a + r + 1);

    for (int i = 0; i < n; i++)
    if (a[i] != b[i]) {
        cout << "no\n";
        return 0;
    }
    cout << "yes\n" << l + 1 << " " << r + 1 << "\n";

    return 0;
}