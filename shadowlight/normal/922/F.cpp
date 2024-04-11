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
    int n, k;
    cin >> n >> k;
    vector <int> d(MAXN, -1);
    vector <int> p;
    for (int i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            d[i] = p.size();
            p.push_back(i);
        }
        for (int j = 0; j <= d[i]; j++) {
            if (i * p[j] >= MAXN) break;
            d[i * p[j]] = j;
        }
    }
    vector <int> cntd(MAXN, 0);
    cntd[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        int x = d[i];
        int a = i;
        int cnt = 0;
        while (d[a] == x) {
            a /= p[x];
            cnt++;
        }
        cntd[i] = (cnt + 1) * cntd[a];
    }
    int sum = 0;
    int m = 1;
    vector <bool> exist(MAXN, 0);
    exist[1] = 1;
    while (m < n && sum < k) {
        m++;
        sum += cntd[m] - 1;
        exist[m] = true;
    }
    if (sum < k) {
        cout << "No";
        return 0;
    }
    vector <pair <int, int> > vals;
    for (int i = m / 2 + 1; i <= m; i++) {
        vals.push_back({cntd[i] - 1, i});
    }
    sort(vals.rbegin(), vals.rend());
    int x = sum - k;
    for (int i = 0; i < vals.size(); i++) {
        //cout << vals[i].first << " " << vals[i].second << "\n";
        if (!x) break;
        if (x < vals[i].first) continue;
        x -= vals[i].first;
        exist[vals[i].second] = false;
    }
    //cout << sum << "\n";
    vector <int> ans;
    cout << "Yes\n";
    for (int i = 0; i < MAXN; i++) {
        if (exist[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
}