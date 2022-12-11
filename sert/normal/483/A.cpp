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
const ll N = 1e4 + 7;

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

ll l, r;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> l >> r;

    for (ll i = l; i <= r; i++)
        for (ll j = i + 1; j <= r; j++)
            for (ll k = j + 1; k <= r; k++) {
                if (i == j || i == k || k == j) continue;
                if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) > 1) {
                    cout << i << " " << j << " " << k << "\n";
                    return 0;
                }
            }
    cout << -1;

    return 0;
}