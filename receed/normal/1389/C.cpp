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
    int t;
    cin >> t;
    rep(z, t) {
        string s;
        cin >> s;
        int ans = 0, ca;
        rep(i, 10) {
            ca = 0;
            for (char c : s)
                if (c == '0' + i)
                    ca++;
            ans = max(ans, ca);
            rep(j, 10) {
                ca = 0;
                for (char c : s)
                    if (ca % 2 && c == '0' + j || ca % 2 == 0 && c == '0' + i)
                        ca++;
                ans = max(ans, ca / 2 * 2);
            }
        }
        cout << s.size() - ans << '\n';
    }
}