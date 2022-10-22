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
    for (int t = 0; t < n; t++) {
        int x;
        cin >> x;
        bool fl = false;
        for (int a = 0; a * 3 <= x; a++) {
            if ((x - 3 * a) % 7 == 0) {
                fl = 1;
                break;
            }
        }
        if (fl) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}