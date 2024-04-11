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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int r = 1;
    int res = 0;
    vector <bool> skip(n + 1, 0);
    for (int i = 0; i < n; i++) {
        while (r <= n && cnt[r]) {
            r++;
        }
        if (cnt[a[i]] > 1) {
            if (r > a[i] && !skip[a[i]]) {
                skip[a[i]] = 1;
                continue;
            }
            cnt[r]++;
            cnt[a[i]]--;
            a[i] = r;
            res++;
        }
    }
    cout << res << "\n";
    for (int x : a) {
        cout << x << " ";
    }
}