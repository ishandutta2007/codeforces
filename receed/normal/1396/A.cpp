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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
        cin >> a[i];
    cout << 1 << ' ' << n << '\n';
    rep(i, n)
        cout << -a[i] * n << ' ';
    cout << '\n';
    if (n == 1) {
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        return 0;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    rep(i, n - 1)
        cout << a[i] * (n - 1) << ' ';
    cout << '\n';
    cout << 2 << ' ' << n << '\n';
    rep(i, n - 2)
        cout << "0 ";
    cout << a[n - 1] * (n - 1);
}