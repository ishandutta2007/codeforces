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

const int N = 500001;
int a[N], eu[N], ev[N], d[N], t[N], qv[N], p[N], v1[N], v2[N];
vector<int> li[N];
set<int> ss[N];

void merge(int u, int v) {
    if (li[u].size() < li[v].size())
        swap(u, v);
    for (int i : li[v]) {
        p[i] = u;
        li[u].push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, n) {
        cin >> a[i];
        li[i].push_back(i);
        p[i] = i;
    }
    rep(i, m) {
        cin >> eu[i] >> ev[i];
        eu[i]--; ev[i]--;
    }
    rep(i, q) {
        v1[i] = v2[i] = -1;
        cin >> t[i] >> qv[i];
        qv[i]--;
        if (t[i] == 2)
            d[qv[i]] = 1;
    }
    rep(i, m)
        if (!d[i]) {
            int u = p[eu[i]], v = p[ev[i]];
            if (u != v)
                merge(u, v);
        }
    for (int i = q - 1; i >= 0; i--)
        if (t[i] == 2) {
            int u = p[eu[qv[i]]], v = p[ev[qv[i]]];
            if (u != v) {
                if (li[u].size() < li[v].size())
                    swap(u, v);
                merge(u, v);
                v1[i] = u;
                v2[i] = v;
            }
        }
    rep(i, n)
        ss[p[i]].insert(a[i]);
    rep(i, q) {
        if (t[i] == 1) {
            int cp = p[qv[i]];
            if (ss[cp].empty())
                cout << "0\n";
            else {
                cout << *--ss[cp].end() << '\n';
                ss[cp].erase(--ss[cp].end());
            }
        }
        else if (v1[i] != -1) {
            for (int j : li[v2[i]]) {
                p[j] = v2[i];
                if (ss[v1[i]].count(a[j])) {
                    ss[v1[i]].erase(a[j]);
                    ss[v2[i]].insert(a[j]);
                }
            }
        }
    }
}