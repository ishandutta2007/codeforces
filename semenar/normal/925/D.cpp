#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

int inf = (int)1e9 + 7;

struct fraction {
    int p;
    int q;

    friend bool operator<(fraction a, fraction b);
};

bool operator<(fraction a, fraction b) {
    return (long long)a.p * b.q < (long long)a.q * b.p;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    // 1
    for (auto elem : gr[0]) {
        if (elem == n - 1) {
            cout << 1 << endl;
            cout << "1 " << n << endl;
            return;
        }
    }

    // 2
    for (auto elem : gr[0]) {
        for (auto v : gr[elem]) {
            if (v == n - 1) {
                cout << 2 << endl;
                cout << 1 << ' ' << elem + 1 << ' ' << n << endl;
                return;
            }
        }
    }

    // 3
    vector<bool> appr(n, false);
    for (auto elem : gr.back()) appr[elem] = true;

    for (auto elem : gr[0]) {
        for (auto v : gr[elem]) {
            if (appr[v]) {
                cout << 3 << endl;
                cout << 1 << ' ' << elem + 1 << ' ' << v + 1 << ' ' << n << endl;
                return;
            }
        }
    }

    // 4: triangle
    for (int i = 0; i < n; i++) appr[i] = true;
    appr[0] = false;
    for (auto elem : gr[0]) appr[elem] = false;

    for (auto elem : gr[0]) {
        for (auto v : gr[elem]) {
            if (appr[v]) {
                cout << 4 << endl;
                cout << 1 << ' ' << elem + 1 << ' ' << v + 1 << ' ' << 1 << ' ' << n << endl;
                return;
            }
        }
    }

    // 5: triangle without fixed point
    vector<bool> used(n, true);
    for (auto elem : gr[0]) used[elem] = false;

    vector<pair<int, int>> new_world_order;
    for (auto elem : gr[0]) new_world_order.emplace_back(gr[elem].size(), elem);

    sort(new_world_order.begin(), new_world_order.end());

    for (auto fellow : new_world_order) {
        int elem = fellow.second;
        if (used[elem]) continue;
        used[elem] = true;

        unordered_set<int> vert;
        vert.insert(elem);
        for (auto v : gr[elem]) {
            vert.insert(v);
        }
        for (auto v : gr[elem]) {
            if (used[v]) continue;
            used[v] = true;

            for (auto u : gr[v]) {
                if (vert.count(u) == 0) {
                    cout << 5 << endl;
                    cout << 1 << ' ' << elem + 1 << ' ' << v + 1 << ' ' << u + 1 << ' ' << elem + 1 << ' ' << n << endl;
                    return;
                }
            }
        }
    }

    // Answer either is no more than 5, or is -1.
    cout << -1 << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}