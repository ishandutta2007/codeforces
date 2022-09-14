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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 18;
int tr[N * 2], cc[26], a[N];
vector<int> li[26];

void add(int v, int d) {
    d -= tr[N + v];
    for (int i = N + v; i; i /= 2)
        tr[i] += d;
}

int getf(int p, int v=1, int l=0, int r=N) {
    if (!tr[v] || r <= p)
        return -1;
    if (r - l == 1)
        return l;
    int x = getf(p, v * 2, l, (l + r) / 2);
    if (x != -1)
        return x;
    return getf(p, v * 2 + 1, (l + r) / 2, r);
}

set<pair<int, int>> q;
void dec(int c) {
    q.erase({cc[c], c});
    cc[c]--;
    if (cc[c] > 0)
        q.insert({cc[c], c});
}

int sum(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[v];
    return sum(cl, cr, v * 2, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, c;
    cin >> t;
    rep(z, t) {
        string s;
        cin >> s;
        n = s.size();
        rep(i, n) {
            a[i] = s[i] - 'a';
            add(i, 1);
        }
        set<int> es;
        rep(i, 26) {
            cc[i] = 0;
            li[i].clear();
        }
        rep(i, n - 1)
            if (a[i] == a[i + 1]) {
                es.insert(i);
                cc[a[i]]++;
                li[a[i]].push_back(i);
            }
        q.clear();
        rep(i, 26)
            if (cc[i])
                q.insert({cc[i], i});
        vector<pair<int, int>> ans;
        while (q.size() > 1) {
            c = (*--q.end()).second;
            int fl = 0;
            while (!li[c].empty()) {
                int p = li[c].back();
                li[c].pop_back();
                auto it = es.lower_bound(p);
                if (it == es.end() || *it != p)
                    continue;
                if (it != es.begin() && a[*prev(it)] != c)
                    --it;
                if (next(it) == es.end() || a[*next(it)] == a[*it])
                    continue;
                int p1 = *it + 1, p2 = *next(it);
                dec(a[p1]);
                dec(a[p2]);
                if (next(next(it)) != es.end())
                    li[a[*next(next(it))]].push_back(*next(next(it)));
                if (it != es.begin())
                    li[a[*prev(it)]].push_back(*prev(it));
                es.erase(next(it));
                es.erase(it);
                ans.push_back({sum(0, p1) + 1, sum(0, p2) + 1});
                while (p1 != -1 && p1 <= p2) {
                    add(p1, 0);
                    p1 = getf(p1);
                }
                fl = 1;
                break;
            }
            assert(fl);
        }
        for (int i : es) {
            ans.push_back({sum(0, i) + 1, sum(0, i) + 1});
            add(i, 0);
        }
        ans.push_back({1, tr[1]});
        cout << ans.size() << '\n';
        for (auto &pp : ans)
            cout << pp.first << ' ' << pp.second << '\n';
        rep(i, n)
            add(i, 0);
    }
}