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
const int N = 34;
const ld zero = 0;

ld ch, zn = 1;
int n, k, a[N], t;

int ki() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                ans++;
    return ans;
}

void go(int kol) {
    if (kol == k) {
        ch += ki();
        return;
    }
    for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
        reverse(a + i, a + j + 1);
        go(kol + 1);
        reverse(a + i, a + j + 1);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    t = (n * (n + 1)) / 2;
    for (int i = 0; i < k; i++) zn *= t;

    //cerr << zn << "\n";

    go(0);

    cout.precision(12);
    cout << fixed << ch / zn;

    return 0;
}