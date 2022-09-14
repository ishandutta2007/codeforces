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

const int N = 500002;
vector<int> g[N];
int used[N];
int e, cv;

void dfs(int v) {
    used[v] = 1;
    cv++;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n)
        cin >> a[i].first >> a[i].second;
    sort(all(a));
    set<pair<int, int>> s;
    rep(i, n) {
        auto it = s.lower_bound(make_pair(a[i].first, 0));
        while (it != s.end() && (*it).first < a[i].second) {
            e++;
            g[i].push_back((*it).second);
            g[(*it).second].push_back(i);
            if (e >= n)
                break;
            it++;
        }
        if (e >= n)
            break;
        s.insert({a[i].second, i});
    }
    dfs(0);
    if (e == n - 1 && cv == n)
        cout << "YES";
    else
        cout << "NO";
}