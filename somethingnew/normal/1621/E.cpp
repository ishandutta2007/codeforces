#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#include "deque"
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int m, n;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    while (a.size() > m)
        a.pop_back();
    reverse(all(a));
    n = m;
    vector<pair<int, int>> bind(n);
    vector<int> b(n);
    vector<vector<int>> stud(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int sm = 0;
        while (k--) {
            int t;
            cin >> t;
            sm += t;
            stud[i].push_back(t);
        }
        bind[i] = {(sm + stud[i].size() - 1) / stud[i].size(), i};
    }
    sort(all(bind));
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        b[i] = bind[i].first;
        pos[bind[i].second] = i;
    }
    vector<int> prefmay(n + 1), sufmay(n + 1);
    prefmay[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= b[i]) {
            prefmay[i + 1] = prefmay[i];
        } else {
            prefmay[i + 1] = 0;
        }
    }
    sufmay[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= b[i])
            sufmay[i] = sufmay[i + 1];
        else
            sufmay[i] = 0;
    }
    vector<int> leftmay(n), rightmay(n);
    for (int i = 1; i < n; ++i) {
        rightmay[i] = rightmay[i - 1];
        leftmay[i] = leftmay[i - 1];
        if (a[i] < b[i - 1])
            leftmay[i]++;
        if (a[i - 1] < b[i])
            rightmay[i]++;
    }
    for (int i = 0; i < n; ++i) {
        int sm = 0;
        for (auto j : stud[i])
            sm += j;
        for (auto j : stud[i]) {
            int nb = (sm - j + stud[i].size() - 2) / (stud[i].size() - 1);
            int newpos = lower_bound(all(b), nb) - b.begin();
            int lastpos = pos[i];
            if (lastpos < newpos) {
                newpos--;
                bool ok = 1;
                if (prefmay[lastpos] == 0)
                    ok = 0;
                if (sufmay[newpos + 1] == 0)
                    ok = 0;
                int t = rightmay[newpos] - rightmay[lastpos];
                if (t != 0)
                    ok = 0;
                if (nb > a[newpos])
                    ok = 0;
                cout << ok;
            } else {
                bool ok = 1;
                if (prefmay[newpos] == 0)
                    ok = 0;
                if (sufmay[lastpos + 1] == 0)
                    ok = 0;
                int t = leftmay[lastpos] - leftmay[newpos];
                if (t != 0)
                    ok = 0;
                if (nb > a[newpos])
                    ok = 0;
                cout << ok;
            }
        }
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}