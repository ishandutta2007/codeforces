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
    vector <int> a(n, 0);
    int pr;
    cin >> pr;
    a[0] = pr;
    int y = 1;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (abs(x - pr) != 1) {
            if (y != 1 && y != abs(x - pr)) {
                cout << "NO\n";
                return 0;
            }
            y = abs(x - pr);
        }
        pr = x;
    }
    if (!y) {
        cout << "NO\n";
        return 0;
    }
    if (y != 1) {
        for (int i = 1; i < n; i++) {
            int t = a[i] - a[i - 1];
            if (t == 1 && a[i - 1] % y == 0) {
                cout << "NO\n";
                return 0;
            }
            if (t == -1 && a[i - 1] % y == 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    cout << 1000000000 << " " << y << "\n";
}