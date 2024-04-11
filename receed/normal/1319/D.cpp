#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

const int N = 200001;
int a[N], d[N], fl[N];
vector<int> g[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m, u, v, k;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[v].push_back(u);
    }
    cin >> k;
    rep(i, k) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n)
        d[i] = N;
    d[a[k - 1]] = 0;
    queue<int> q;
    q.push(a[k - 1]);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : g[v]) {
            if (d[i] == N) {
                d[i] = d[v] + 1;
                q.push(i);
            }
            else if (d[i] == d[v] + 1)
                fl[i] = 1;
        }
    }
    int mn = 0, mx = 0;
    rep(i, k - 1) {
        if (d[a[i]] != d[a[i + 1]] + 1)
            mn++;
        else if (fl[a[i]])
            mx++;
    }
    mx += mn;
    cout << mn << ' ' << mx;
}