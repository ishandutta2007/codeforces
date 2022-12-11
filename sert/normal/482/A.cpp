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
const int N = 1e4 + 7;

ll sz(ll siz) {
    return (siz * (siz - 1ll)) / 2;
}

ll n, k, d, mx, cur;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n - k; i++)
        cout << i + 1 << " ";
    mx = 1;
    d = k;
    cur = n - k;
    for (int i = 0; i < k; i++) {
        cur += mx * d;
        mx = -mx;
        d--;
        cout << cur << " ";
    }

    return 0;
}