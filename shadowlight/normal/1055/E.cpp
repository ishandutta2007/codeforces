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

int n, s, m, k;

vector <pair <int, int> > b;
vector <int> a;

bool can(int x) {
    vector <vector <int> > p(m + 1, vector <int> (b.size(), -INF));
    vector <vector <int> > f(m + 1, vector <int> (b.size(), -INF));
    f[0][0] = 0;
    for (int i = 0; i < b.size(); i++) {
        p[0][i] = 0;
    }
    vector <int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        if (a[i] <= x) {
            pref[i + 1]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        int lnow = b.back().first, rnow = b.back().second;
        for (int pn = 0; pn < (int) b.size() - 1; pn++) {
            int sum = pref[rnow + 1] - pref[max(lnow, b[pn].second + 1)] + f[i - 1][pn];
            if (sum > f[i][b.size() - 1]) {
                f[i][b.size() - 1] = sum;
                p[i][b.size() - 1] = pn;
            }
        }
        for (int j = (int) b.size() - 2; j >= 0; j--) {
            int lnow = b[j].first, rnow = b[j].second;
            int lt = p[i - 1][j], rt = p[i][j + 1];
            //cout << lt << " " << rt << "\n";
            for (int pn = lt; pn <= rt; pn++) {
                int sum = pref[rnow + 1] - pref[max(lnow, b[pn].second + 1)] + f[i - 1][pn];
                if (sum > f[i][j]) {
                    f[i][j] = sum;
                    p[i][j] = pn;
                }
            }
        }
        for (int j = 0; j < (int) b.size() - 1; j++) {
            if (f[i][j] > f[i][j + 1]) {
                f[i][j + 1] = f[i][j];
                p[i][j + 1] = p[i][j];
            }
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (f[m][i] >= k) {
            return true;
        }
    }
    return false;
}

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
    cin >> n >> s >> m >> k;
    vector <pair <int, int> > all;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < s; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        all.push_back({l, r});
    }
    sort(all.begin(), all.end(), [&](pair <int, int> x, pair <int, int> y) {
        if (x.first == y.first) {
            return x.second > y.second;
         }
         return x.first < y.first;
    });
    int last = -1;
    b.push_back({-1, -1});
    for (int i = 0; i < s; i++) {
        int l = all[i].first, r = all[i].second;
        if (r <= last) {
            continue;
        }
        b.push_back({l, r});
        last = r;
    }
    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << r << "\n";
}