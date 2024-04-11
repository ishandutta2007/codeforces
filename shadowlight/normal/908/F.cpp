#include <bits/stdc++.h>
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
    vector <int> g, r, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'G') {
            g.push_back(x);
        } else if (c == 'R') {
            r.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    ll sum = 0;
    if (!g.size()) {
        for (int i = 1; i < (int) r.size(); i++) {
            sum += r[i] - r[i - 1];
        }
        for (int i = 1; i < (int) b.size(); i++) {
            sum += b[i] - b[i - 1];
        }
        cout << sum;
        return 0;
    }
    int j = 0, k = 0;
    if (r.size() && r[0] < g[0]) {
        sum += g[0] - r[0];
    }
    if (b.size() && b[0] < g[0]) {
        sum += g[0] - b[0];
    }
    j = upper_bound(r.begin(), r.end(), g[0]) - r.begin();
    k = upper_bound(b.begin(), b.end(), g[0]) - b.begin();
    if (r.size() && r.back() > g.back()) {
        sum += r.back() - g.back();
    }
    if (b.size() && b.back() > g.back()) {
        sum += b.back() - g.back();
    }
    for (int i = 1; i < g.size(); i++) {
        int pr = g[i - 1];
        int max1 = -1, max2 = -1;
        while (j < r.size() && r[j] < g[i]) {
            max1 = max(max1, r[j] - pr);
            pr = r[j];
            j++;
        }
        max1 = max(max1, g[i] - pr);
        pr = g[i - 1];
        while (k < b.size() && b[k] < g[i]) {
            max2 = max(max2, b[k] - pr);
            pr = b[k];
            k++;
        }
        max2 = max(max2, g[i] - pr);
        int len = g[i] - g[i - 1];
        //cout << max1 << " " << max2 << "\n";
        sum += min(2 * len, 3 * len - max1 - max2);
    }
    cout << sum;
}