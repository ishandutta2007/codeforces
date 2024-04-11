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

ll a[26], b[26][26];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
    cin >> s;
    for (char c : s) {
        rep(i, 26)
            b[i][c - 'a'] += a[i];
        a[c - 'a']++;
    }
    ll ans = 0;
    rep(i, 26) {
        ans = max(ans, a[i]);
        rep(j, 26)
            ans = max(ans, b[i][j]);
    }
    cout << ans;
}