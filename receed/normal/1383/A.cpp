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
    int t, n, x, y, f, m = 20;
    string a, b;
    cin >> t;
    rep(z, t) {
        cin >> n >> a >> b;
        f = 0;
        vector<set<int>> s(m);
        rep(i, n) {
            x = a[i] - 'a';
            y = b[i] - 'a';
            if (x > y) {
                f = 1;
                break;
            }
            s[x].insert(y);
        }
        if (f)
            cout << "-1\n";
        else {
            int ans = 0, p;
            rep(i, m - 1) {
                if (s[i].count(i))
                    s[i].erase(i);
                if (s[i].empty())
                    continue;
                p = *s[i].begin();
                for (int j : s[i])
                    s[p].insert(j);
                ans++;
            }
            cout << ans << '\n';
        }
    }
}