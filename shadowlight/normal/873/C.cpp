#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > a(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector <pair <int, int> > cnt(m, {0, 0});
    int pred = -1;
    for (int j = 0; j < m; j++) {
        int ones = 0;
        pred = -1;
        for (int i = 0; i < n; i++) {
            if (!a[i][j]) continue;
            int now = 0;
            for (int l = i; l < i + min(k, n - i); l++) {
                if (a[l][j]) {
                    now++;
                }
            }
            if (now > pred) {
                cnt[j] = {ones, now};
                pred = now;
            }
            ones++;
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < m; i++) {
        ans1 += cnt[i].first;
        ans2 += cnt[i].second;
    }
    cout << ans2 << " " << ans1;
}