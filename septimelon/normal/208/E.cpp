#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int dfs(int v, int ch, int step, vector<int>& h, vector<int>& in, vector<int>& out, vector<vector<int>>& ins, const vector<vector<int>>& r) {
    in[v] = step;
    h[v] = ch;
    ins[ch].push_back(step);
    ++step;
    for (int i = 0; i < r[v].size(); ++i) {
        step = dfs(r[v][i], ch + 1, step, h, in, out, ins, r) + 1;
    }
    out[v] = step;
    return step;
}

int fgr(int x, const vector<int>& v) {
    int l = -1, r = v.size();

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (v[mid] > x) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> ch(n);
    vector<vector<int>> par(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        --v;
        par[i].push_back(v);
        if (v >= 0) {
            ch[v].push_back(i);
        }
    }

    for (int cj = 0; (1 << cj) < n; ++cj) {
        for (int i = 0; i < n; ++i) {
            if (par[i][cj] == -1) {
                par[i].push_back(-1);
            }
            else {
                par[i].push_back(par[par[i][cj]][cj]);
            }
        }
    }

    vector<int> h(n), in(n), out(n);
    vector<vector<int>> ins(n);
    int cl = 0;
    for (int i = 0; i < n; ++i) {
        if (par[i][0] == -1) {
            cl = dfs(i, 0, cl, h, in, out, ins, ch) + 1;
        }
    }

    /*for (int i = 0; i < n; ++i) {
        cout << i << ":";
        for (int j = 0; j < ins[i].size(); ++j) {
            cout << " " << ins[i][j];
        }
        cout << "\n";
    }*/

    int q;
    cin >> q;
    for (int qq = 0; qq < q; ++qq) {
        int cv, cp;
        cin >> cv >> cp;
        --cv;

        int croot = cv;
        for (int i = 0; (1 << i) < n; ++i) {
            if (cp & (1 << i)) {
                croot = par[croot][i];
            }
            if (croot == -1) {
                break;
            }
        }
        if (croot == -1 || cp >= n) {
            cout << "0 ";
            continue;
        }

        //cout << "(" << h[croot] + cp << "," << h[cv] << ")";
        //cout << ins[h[cv]].size() << ", ";
        int dist = fgr(out[croot], ins[h[cv]]) - fgr(in[croot], ins[h[cv]]) - 1;
        cout << dist << " ";
    }

    return 0;
}