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
    int ma = -1, mb = -1;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            ma = max(ma, x);
            mb = max(mb, y);
        } else {
            int h, w;
            cin >> h >> w;
            if (h > w) swap(h, w);
            if (h < ma || w < mb) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}