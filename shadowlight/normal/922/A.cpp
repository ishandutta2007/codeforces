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
    int x, y;
    cin >> y >> x;
    if (!x) {
        cout << "No";
        return 0;
    }
    int now = x - 1;
    if (!now && y) {
        cout << "No";
        return 0;
    }
    if (y < now || (y - now) % 2) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
}