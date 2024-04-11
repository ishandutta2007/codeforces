#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= n; i++) cout << i << ' ';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << endl;
        exit(0);
    }
    cout << "Second" << endl;
    vector<int> first(n, -1), second(n, -1);
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        x--;
        if (first[x] == -1) {
            first[x] = i;
        } else {
            second[x] = i;
        }
    }
    vector<vector<tuple<int, int, bool>>> g(n); //  -
    for (int r = 0; r < n; r++) {
        g[first[r] % n].pb({second[r] % n, r, true});
        g[second[r] % n].pb({first[r] % n, r, false});
    }
    vector<bool> who(n);
    vector<bool> used(n, false), usedd(n, false);
    for (int v = 0; v < n; v++) {
        deque<int> q = {v};
        used[v] = true;
        while (!q.empty()) {
            int gg = q.front();
            q.pop_front();
            bool ok = false;
            for (auto uh : g[gg]) {
                int u = get<0>(uh);
                if (!used[u]) {
                    used[u] = true;
                    q.pb(u);
                    usedd[get<1>(uh)] = true;
                    who[get<1>(uh)] = get<2>(uh);
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                for (auto uh : g[gg]) {
                    int u = get<0>(uh);
                    if (!usedd[get<1>(uh)]) {
                        usedd[get<1>(uh)] = true;
                        who[get<1>(uh)] = get<2>(uh);
                        break;
                    }
                }
            }
        }
    }
    int aa = 0;
    for (int i = 0; i < n; i++) {
        if (who[i]) {
            aa += first[i];
        } else {
            aa += second[i];
        }
    }
    if (aa % (2 * n) != 0) {
        for (int i = 0; i < n; i++) {
            if (!who[i]) {
                cout << first[i] << ' ';
            } else {
                cout << second[i] << ' ';
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (who[i]) {
                cout << first[i] << ' ';
            } else {
                cout << second[i] << ' ';
            }
        }
    }
    cout << endl;
}