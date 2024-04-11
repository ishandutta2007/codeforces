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
    int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i, n)
            cin >> a[i];
        rep(i, n + 1) {
            b = a;
            rep(j, i)
                b[j] *= -1;
            ll c1 = 0, c2 = 0;
            rep(i, n - 1) {
                if (b[i + 1] - b[i] >= 0)
                    c1++;
                if (b[i + 1] - b[i] <= 0)
                    c2++;
            }
            if (c1 >= (n - 1) / 2 && c2 >= (n - 1) / 2)
                break;
        }
        for (ll i : b)
            cout << i << ' ';
        cout << '\n';
    }
}