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
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    vector <int> x(n + m);
    for (int i = 0; i < n + m; i++) {
        cin >> x[i];
    }
    vector <int> all;
    vector <int> t(n + m);
    for (int i = 0; i < n + m; i++) {
        cin >> t[i];
        if (t[i]) {
            all.push_back(x[i]);
        }
    }
    int now = -1;
    vector <int> res(m, 0);
    for (int i = 0; i < n + m; i++) {
        if (t[i]) {
            now++;
        } else {
            if (now == -1) {
                res[0]++;
            } else if (now == m - 1) {
                res[m - 1]++;
            } else if (x[i] - all[now] <= all[now + 1] - x[i]) {
                res[now]++;
            } else {
                res[now + 1]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
}