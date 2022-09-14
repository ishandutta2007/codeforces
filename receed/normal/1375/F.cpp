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

ll q;
ll a[3];

ll go(ll r) {
    cout << r << endl;
    cin >> q;
    q--;
    a[q] += r;
    return q;
}

int main() {
    rep(i, 3)
        cin >> a[i];
    cout << "First" << endl;
    ll p = go(max(a[0], max(a[1], a[2])) * 2);
    go(a[p] * 3 - a[0] - a[1] - a[2]);
    go((max(a[0], max(a[1], a[2])) - min(a[0], min(a[1], a[2]))) / 2);
}