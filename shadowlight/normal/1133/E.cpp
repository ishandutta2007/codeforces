#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    vector <int> a(n);
    map <int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    int r = 0;
    vector <vector <int> > d(n + 1, vector <int> (k + 2, 0));
    for (int l = 0; l < n; l++) {
        while (r < n && a[r] <= a[l] + 5) {
            r++;
        }
        int sum = r - l;
        for (int i = 0; i <= k; i++) {
            d[l + 1][i] = max(d[l + 1][i], d[l][i]);
            d[r][i + 1] = max(d[r][i + 1], d[l][i] + sum);
        }
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = max(res, d[n][i]);
    }
    cout << res;
}