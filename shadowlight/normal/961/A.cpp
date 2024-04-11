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
    int n, m;
    cin >> n >> m;
    vector <int> cnt(n, 0);
    int res = INF;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    for (int i = 0; i < n; i++) {
        res = min(res, cnt[i]);
    }
    cout << res;
}