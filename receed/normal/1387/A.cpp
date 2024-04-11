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

const int N = 100001;
vector<pair<int, int>> g[N];
vector<int> li, lb;

ll used[N], b[N], k[N];
ld ans[N], x, eps = 1e-6;
int fx = 0;

void dfs(int v, ll ck, ll cb) {
    li.push_back(v);
    used[v] = 1;
    k[v] = ck;
    b[v] = cb;
    li.push_back(v);
    lb.push_back(-cb * ck);
    for (auto &p : g[v]) {
        if (used[p.first]) {
            if (ck != k[p.first]) {
                if (cb + b[p.first] != p.second) {
                    cout << "NO";
                    exit(0);
                }
            }
            else {
                ld cx = (ld) (p.second - b[p.first] - cb) / (ck + k[p.first]);
                if (fx && abs(cx - x) > eps) {
                    cout << "NO";
                    exit(0);
                }
                fx = 1;
                x = cx;
            }
        }
        else
            dfs(p.first, -ck, p.second - cb);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(8);
    int n, m, u, v, c;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v >> c;
        u--; v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    rep(i, n) {
        if (used[i])
            continue;
        fx = 0;
        li.clear();
        lb.clear();
        dfs(i, 1, 0);
        if (!fx) {
            sort(all(lb));
            x = lb[lb.size() / 2];
        }
        for (int j : li)
            ans[j] = k[j] * x + b[j];
    }
    cout << "YES\n";
    rep(i, n)
        cout << ans[i] << ' ';
}