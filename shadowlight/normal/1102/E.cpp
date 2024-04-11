#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 998244353;
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
    vector <int> a(n);
    map <int, int> last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    int res = 1;
    map <int, bool> used;
    used[a[0]] = 1;
    int st = last[a[0]];
    for (int i = 1; i < n; i++) {
        if (!used[a[i]]) {
            if (i > st) {
                res = res * 2 % INF;
            }
            st = max(st, last[a[i]]);
            used[a[i]] = 1;
        }
    }
    cout << res;
}