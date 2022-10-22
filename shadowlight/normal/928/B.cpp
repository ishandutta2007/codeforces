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
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector <int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        int pr = p[i];
        if (pr == -1) {
            cnt[i] = min(n - 1, i + k) - max(0, i - k) + 1;
            continue;
        }
        int r = min(n - 1, i + k);
        int l = max(i - k, pr + k + 1);
        cnt[i] = cnt[pr];
        if (l <= r) {
            cnt[i] += r - l + 1;
        }
    }
    for (int x : cnt) {
        cout << x << " ";
    }
    return 0;
}