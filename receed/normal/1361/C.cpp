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

const int N = 1 << 20;
int a[N], pos[N], used[N];
vector<pair<int, int>> g[N];
vector<int> ans;

void dfs(int v) {
    while (pos[v] < g[v].size()) {
        if (!used[g[v][pos[v]].second >> 1]) {
            used[g[v][pos[v]].second >> 1] = 1;
            auto ce = g[v][pos[v]];
            pos[v]++;
            dfs(ce.first);
            ans.push_back(ce.second ^ 1);
            ans.push_back(ce.second);
        }
        else
            pos[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    rep(i, 2 * n)
        cin >> a[i];
    for (int j = 20; j >= 0; j--) {
        int m = (1 << j) - 1;
        rep(i, N) {
            g[i].clear();
            pos[i] = 0;
            used[i] = 0;
            ans.clear();
        }
        rep(i, 2 * n)
            g[a[i] & m].push_back({a[i ^ 1] & m, i});
        int f = 0;
        rep(i, m + 1)
            if (g[i].size() % 2)
                f = 1;
        if (f)
            continue;
        int pp = 0;
        while (g[pp].empty())
            pp++;
        dfs(pp);
        if (ans.size() == 2 * n) {
            cout << j << '\n';
            for (int i : ans)
                cout << i + 1 << ' ';
            break;
        }
    }
}