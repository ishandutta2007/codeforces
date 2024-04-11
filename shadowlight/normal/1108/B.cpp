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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = a[n - 1], y;
    vector <bool> used(n, false);
    map <int, bool> was;
    for (int i = 0; i < n; i++) {
        int d = a[i];
        if (x % d == 0 && !was[d]) {
            was[d] = true;
            used[i] = true;
        } else {
            y = d;
        }
    }
    cout << x << " " << y << "\n";
}