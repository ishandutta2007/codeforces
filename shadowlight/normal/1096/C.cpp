#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

void solve() {
    double x;
    cin >> x;
    for (int i = 3; i <= 500; i++) {
        double d = (180.0 / i);
        double now = 0;
        for (int j = 1; j < i - 1; j++) {
            now += d;
            if (abs(x - now) < EPS) {
                cout << i << "\n";
                return;
            }
        }
    }
}

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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}