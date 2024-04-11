#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
pair<int, int> mrg(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

bool in(pair<int, int> a, int x) {
    return (a.first <= x and x <= a.second);
}
struct elem {
    int first, second;
    elem * next;
    int turn;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(n);
    vector<int> num(n);
    vector<vector<pair<int, pair<int, int>>>> abinap(n + 1, vector<pair<int, pair<int, int>>>(20)), bbinap(n + 1, vector<pair<int, pair<int, int>>>(20));
    for (int i = 0; i < n; ++i) {
        cin >> num[i] >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    for (int i = 0; i < n; ++i) {
        abinap[i][0] = {i + 1, a[i]};
        bbinap[i][0] = {i + 1, b[i]};
    }
    abinap[n][0] = bbinap[n][0] = {n, {0, m}};
    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i <= n; ++i) {
            abinap[i][k].first = abinap[abinap[i][k-1].first][k-1].first;
            abinap[i][k].second = mrg(abinap[i][k-1].second, abinap[abinap[i][k-1].first][k-1].second);
            bbinap[i][k].first = bbinap[bbinap[i][k-1].first][k-1].first;
            bbinap[i][k].second = mrg(bbinap[i][k-1].second, bbinap[bbinap[i][k-1].first][k-1].second);
        }
    }
    vector<int> numa(n), numb(n);
    int zeroa = 0, zerob = 0;
    for (int i = 0; i < n; ++i) {
        int x = num[i];
        int ap = i, bp = i;
        for (int k = 19; k >= 0; --k) {
            if (in(abinap[ap][k].second, x)) {
                ap = abinap[ap][k].first;
            }
            if (in(bbinap[bp][k].second, x)) {
                bp = bbinap[bp][k].first;
            }
        }
        numa[i] = ap;
        numb[i] = bp;
    }
    for (int k = 19; k >= 0; --k) {
        if (in(abinap[zeroa][k].second, 0)) {
            zeroa = abinap[zeroa][k].first;
        }
        if (in(bbinap[zerob][k].second, 0)) {
            zerob = bbinap[zerob][k].first;
        }
    }
    vector<vector<elem>> dp(n + 1);
    dp[n] = {{n, n, nullptr, -1}};
    for (int i = n - 1; i >= 0; --i) {
        vector<elem> turns;
        for (elem &turn : dp[i + 1]) {
            if (turn.first <= numa[i]) {
                turns.push_back({i, turn.second, &turn, 0});
            }
            if (turn.second <= numb[i]) {
                turns.push_back({turn.first, i, &turn, 1});
            }
        }
        if (turns.empty())
            continue;
        elem t1 = turns[0], t2 = turns[0];
        for (auto i : turns) {
            if (t1.first > i.first)
                t1 = i;
            if (t1.first == i.first and t1.second > i.second)
                t1 = i;
            if (t2.second > i.second)
                t2 = i;
            if (t2.second == i.second and t2.first > i.first)
                t2 = i;
        }
        dp[i] = {t1, t2};
    }

    elem * ttt = nullptr;
    for (auto &i : dp[0]) {
        if (i.second == 0 and i.first <= zeroa)
            ttt = &i;
        if (i.first == 0 and i.second <= zerob)
            ttt = &i;
    }
    if (ttt == nullptr) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << ttt->turn << ' ';
        ttt = ttt->next;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
    int n = 1;
    while (n--)
        solve();
}