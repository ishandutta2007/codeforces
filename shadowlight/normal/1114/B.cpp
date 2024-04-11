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
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    vector <bool> used(n, 0);
    ll sum = 0;
    for (int i = 0; i < m * k; i++) {
        used[a[i].second] = true;
        sum += a[i].first;
    }
    int cnt = 0;
    vector <int> res;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cnt++;
        }
        if (cnt == m) {
            res.push_back(i + 1);
            cnt = 0;
        }
    }
    res.pop_back();
    cout << sum << "\n";
    for (ll x : res) {
        cout << x << " ";
    }
}