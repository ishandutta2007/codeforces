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
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n) {
        cout << 0;
        return 0;
    }
    if (l == 1) {
        cout << abs(r - pos) + 1;
        return 0;
    }
    if (r == n) {
        cout << abs(l - pos) + 1;
        return 0;
    }
    cout << min(abs(l - pos), abs(r - pos)) + r - l + 2;
}