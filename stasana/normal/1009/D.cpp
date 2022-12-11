#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

set<pair<int, int>> edges;
ll n, m;

ll gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

pair<ll, ll> getEdge(ll v, ll u) {
    if (v > u) {
        return make_pair(u, v);
    }
    return make_pair(v, u);
}

void bfs() {
    for (ll v = 1; m > 0 && v <= n; ++v) {
        for (ll u = v + 2; m > 0 && u <= n; ++u) {
            if (gcd(v, u) == 1) {
                if (edges.find(getEdge(v, u)) == edges.end()) {
                    edges.insert(getEdge(v, u));
                    --m;
                }
            }
        }
    }
}

int main() {
    start();
    cin >> n >> m;
    if (m < n - 1) {
        cout << "Impossible";
        return 0;
    }
    if (m > n * (n - 1) / 2) {
        cout << "Impossible";
        return 0;
    }
    m -= n - 1;
    for (int i = 1; i < n; ++i) {
        edges.insert(edges.end(), getEdge(i, i + 1));
    }
    bfs();
    if (m > 0) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (auto i : edges) {
        cout << i.first << " " << i.second << "\n";
    }
    //  system("pause");
    return 0;
}