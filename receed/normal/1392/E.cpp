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
    ll n, q, k;
    cin >> n;
    rep(i, n) {
        rep(j, n) {
            if (i + j == 0)
                cout << "0 ";
            else
                cout << (((ll) (i & 1)) << (i + j - 1)) << ' ';
        }
        cout << endl;
    }
    cin >> q;
    rep(i, q) {
        ll x = 0, y = 0;
        cin >> k;
        rep(j, 2 * n - 1) {
            cout << x + 1 << ' ' << y + 1 << endl;
            if ((k & 1) != (x & 1))
                x++;
            else
                y++;
            k >>= 1;
        }
    }
}