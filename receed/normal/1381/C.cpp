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
    int t, n, x, y;
    cin >> t;
    rep(z, t) {
        cin >> n >> x >> y;
        y -= x;
        vector<int> a(n), b(n);
        vector<vector<int>> li(n + 2);
        rep(i, n) {
            cin >> a[i];
            li[a[i]].push_back(i);
        }
        int rc = 0;
        set<pair<int, int>> s;
        rep(i, n + 2) {
            if (!li[i].empty())
                s.insert({li[i].size(), i});
            else
                rc = i;
        }
        rep(i, x) {
            auto p = *--s.end();
            s.erase(--s.end());
            b[li[p.second].back()] = p.second;
            li[p.second].pop_back();
            p.first--;
            if (p.first)
                s.insert(p);
        }
        // for (int i : b)
        //     cout << i << ' ';
        // cout << endl;
        int mx = 0;
        rep(i, n + 2)
            mx = max(mx, (int) li[i].size());
        if (y > (n - x - mx) * 2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (mx * 2 <= n - x) {
            vector<int> ls;
            rep(i, n + 2)
                for (int j : li[i])
                    ls.push_back(j);
            int d = (n - x) / 2;
            rep(i, y)
                b[ls[i]] = a[ls[(i + d) % (n - x)]];
        }
        else {
            vector<int> l1, l2;
            rep(i, n + 2) {
                if (li[i].size() == mx)
                    l1 = li[i];
                else
                    for (int j : li[i])
                        l2.push_back(j);
            }
            rep(i, l2.size()) {
                if (y) {
                    b[l2[i]] = a[l1[i]];
                    y--;
                }
                if (y) {
                    b[l1[i]] = a[l2[i]];
                    y--;
                }
            }
        }
        rep(i, n) {
            if (!b[i])
                b[i] = rc;
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
}