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

ll n, a[N], ps = -1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = a[0];

    for (int i = 0; i < n; i++)
    if (a[i] > a[i + 1]) {
        if (ps != -1) {
            cout << -1;
            return 0;
        } else
            ps = i;
    }

    if (ps == -1) cout << 0;
    else cout << n - 1 - ps;

    return 0;
}