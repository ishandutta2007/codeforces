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
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0;
        return 0;
    }
    if (m != 1) {
        rep(i, n) {
            rep(j, m)
                cout << (i + 1) * (n + j + 1) << ' ';
            cout << '\n';
        }
    }
    else
        rep(i, n)
            cout << i + 2 << '\n';
}