#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, n, k, p;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<ll> a(n);
        ll x = 0;
        rep(i, n) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            cout << "DRAW\n";
            continue;
        }
        p = 30;
        while (!(x & (1ll << p)))
            p--;
        k = 0;
        for (ll i : a)
            if (i & (1ll << p))
                k++;
        if (k % 4 == 1 || n % 2 == 0)
            cout << "WIN\n";
        else
            cout << "LOSE\n";
    }
}