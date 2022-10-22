#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
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

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> tob(n), tow(n);
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u;
        --v;
        if (t == 0) {
            tob[v].push_back(u);
        }
        else {
            tow[v].push_back(u);
        }
    }

    /*for (int i = 0; i < n; ++i) {
        cout << i << ": [ ";
        for (int j = 0; j < tob[i].size(); ++j) {
            cout << tob[i][j] << " ";
        }
        cout << "] { ";
        for (int j = 0; j < tow[i].size(); ++j) {
            cout << tow[i][j] << " ";
        }
        cout << "}\n";
    }*/

    vector<int> stto(n, -1);
    stto[n - 1] = 0;
    vector<int> curi({ n - 1 });
    vector<int> col(n, -1);
    while (!curi.empty()) {
        vector<int> nexi;
        for (int i = 0; i < curi.size(); ++i) {
            int cv = curi[i];
            for (int j = 0; j < tob[cv].size(); ++j) {
                int fr = tob[cv][j];
                if (stto[fr] == -1) {
                    if (col[fr] == 0) {
                        stto[fr] = stto[cv] + 1;
                        nexi.push_back(fr);
                    }
                    else {
                        col[fr] = 1;
                    }
                }
            }
            for (int j = 0; j < tow[cv].size(); ++j) {
                int fr = tow[cv][j];
                if (stto[fr] == -1) {
                    if (col[fr] == 1) {
                        stto[fr] = stto[cv] + 1;
                        nexi.push_back(fr);
                    }
                    else {
                        col[fr] = 0;
                    }
                }
            }
        }
        curi = nexi;
    }

    cout << stto[0] << "\n";
    for (int i = 0; i < n; ++i) {
        cout << max(col[i], 0);
    }
    cout << "\n";

    return 0;
}