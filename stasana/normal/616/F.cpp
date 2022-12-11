#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

struct Node {
    ll len, parent, link, cost;
    vector<ll> next;

    Node() {
        len = 0;
        parent = -1;
        link = -1;
        cost = 0;
        next.resize(26, -1);
    }
};

vector<Node> sa(1);

ll add(ll a, char ch) {
    ll b = sa.size();
    sa.emplace_back();
    sa[b].parent = a;
    sa[b].len = sa[a].len + 1;
    sa[b].link = 0;
    while (a != -1) {
        if (sa[a].next[ch - 'a'] == -1) {
            sa[a].next[ch - 'a'] = b;
            a = sa[a].link;
            continue;
        }
        ll c = sa[a].next[ch - 'a'];
        if (sa[c].parent == a) {
            sa[b].link = c;
            break;
        }
        ll d = sa.size();
        sa.emplace_back();
        sa[d].next = sa[c].next;
        sa[d].link = sa[c].link;
        sa[d].len = sa[a].len + 1;
        sa[d].parent = a;
        sa[c].link = d;
        sa[b].link = d;
        while (a != -1 && sa[a].next[ch - 'a'] == c) {
            sa[a].next[ch - 'a'] = d;
            a = sa[a].link;
        }
        break;
    }
    return sa[sa[b].parent].next[ch - 'a'];
}

vector<ll> used;

void dfs(ll v) {
    used[v] = true;
    for (ll u : sa[v].next) {
        if (u == -1) {
            continue;
        }
        if (!used[u]) {
            dfs(u);
        }
        sa[v].cost += sa[u].cost;
    }
}

inline void solve() {
    ll n;
    cin >> n;
    vector<ll> index;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ll v = 0;
        for (char i : s) {
            v = add(v, i);
        }
        index.emplace_back(v);
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ll v = index[i];
        while (v != -1) {
            sa[v].cost += x;
            v = sa[v].link;
        }
    }
    used.resize(sa.size());
    dfs(0);
    ll result = 0;
    for (auto& i : sa) {
        result = max(result, i.cost * i.len);
    }
    cout << result << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}