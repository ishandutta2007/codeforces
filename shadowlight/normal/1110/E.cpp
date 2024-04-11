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
    int n;
    cin >> n;
    vector <int> c(n), t(n);
    vector <int> ct, tt;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (i) {
            ct.push_back(c[i] - c[i - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (i) {
            tt.push_back(t[i] - t[i - 1]);
        }
    }
    sort(ct.begin(), ct.end());
    sort(tt.begin(), tt.end());
    if (c[0] != t[0] || c.back() != t.back() || ct != tt) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}