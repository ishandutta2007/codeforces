#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
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
    int m, n;
    cin >> m >> n;
    vector <int> cnt(n, 0);
    vector <int> c(m);
    vector <vector <pair <int, int> > > d(n);
    vector <pair <int, int> > all;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p >> c[i];
        p--;
        cnt[p]++;
        if (p) {
            d[p].push_back({c[i], i});
            all.push_back({c[i], i});
        }
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
        sort(d[i].begin(), d[i].end());
    }
    ll res = INF;
    for (int i = 1; i <= m; i++) {
        int exist = cnt[0];
        ll sum = 0;
        vector <bool> used(m, false);
        for (int k = 1; k < n; k++) {
            for (int j = 0; j < cnt[k] - i + 1; j++) {
                exist++;
                used[d[k][j].second] = true;
                sum += d[k][j].first;
            }
        }
        int now = 0;
        while (exist < i) {
            if (!used[all[now].second]) {
                used[all[now].second] = true;
                sum += all[now].first;
                exist++;
            }
            now++;
        }
        //cout << i << " " << sum << "\n";
        res = min(res, sum);
    }
    cout << res;
}