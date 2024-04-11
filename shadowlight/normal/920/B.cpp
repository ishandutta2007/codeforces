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
    int t;
    cin >> t;
    for (int id = 0; id < t; id++) {
        int n;
        cin >> n;
        //vector <int> l(n), r(n);
        int now = 0;
        int tm = 0;
        vector <int> res;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            if (tm < l) {
                tm = l;
            }
            if (tm > r) {
                cout << 0 << " ";
            } else {
                cout << tm << " ";
                tm++;
            }
        }
        cout << "\n";
    }
}