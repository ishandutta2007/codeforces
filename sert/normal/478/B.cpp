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

ll n, m;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n >> m;

    cout << sz(n / m) * (m - n % m) + sz(1 + n / m) * (n % m);
    cout << " " << sz(n - m + 1);

    return 0;
}