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
ll a[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, u, v, c;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v >> c;
        a[u] += c;
        a[v] -= c;
    }
    vector<vector<ll>> ans;
    int pos = 1;
    for (int i = 1; i <= n; i++)
        while (a[i] > 0) {
            while (pos <= n && a[pos] >= 0)
                pos++;
            if (pos > n)
                break;
            ll cx = min(a[i], -a[pos]);
            ans.push_back({i, pos, cx});
            a[i] -= cx;
            a[pos] += cx;
        }
    cout << ans.size() << '\n';
    for (auto &pp : ans)
        cout << pp[0] << ' ' << pp[1] << ' ' << pp[2] << '\n';
}