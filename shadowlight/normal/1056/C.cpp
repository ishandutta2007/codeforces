#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> p[i];
    }
    set <pair <int, int> > free;
    set <pair <int, int> > banned;
    vector <bool> exist(2 * n, true);
    vector <int> need(2 * n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        need[a] = b;
        need[b] = a;
        banned.insert({abs(p[a] - p[b]), (p[a] > p[b] ? a : b)});
    }
    for (int i = 0; i < 2 * n; i++) {
        if (need[i] == -1) {
            free.insert({p[i], i});
        }
    }
    int t;
    cin >> t;
    int now = -1;
    for (int i = 0; i < 2 * n; i++) {
       // cout << "kek " << banned.size() << "\n";
        if (t == 1) {
            if (now != -1) {
                cout << now + 1 << endl;
                now = -1;
            } else {
                if (banned.size()) {
                    auto t = *banned.rbegin();
                    cout << t.second + 1 << endl;
                    banned.erase(t);
                    need[need[t.second]] = -1;
                    need[t.second] = -1;
                } else {
                    auto t = *free.rbegin();
                    cout << t.second + 1 << endl;
                    free.erase(t);
                }
            }
        } else {
            int x;
            cin >> x;
            x--;
            free.erase({p[x], x});
            if (need[x] != -1) {
                now = need[x];
                banned.erase({abs(p[now] - p[x]), x});
                banned.erase({abs(p[now] - p[x]), now});
                need[x] = -1;
                need[now] = -1;
            } else {
                now = -1;
            }
        }
        t = 3 - t;
    }
}