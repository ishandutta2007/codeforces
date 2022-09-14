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
    ll k, r = 1, p;
    cin >> k;
    p = 1;
    string s = "codeforces";
    while (p <= k) {
        p = 1;
        r++;
        rep(i, s.size())
            p *= r;
    }
    rep(i, s.size()) {
        rep(j, r - 1)
            cout << s[i];
        if (p / r * (r - 1) >= k)
            p = p / r * (r - 1);
        else
            cout << s[i];
    }
}