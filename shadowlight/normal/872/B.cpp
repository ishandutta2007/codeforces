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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    int mink = INF, maxk = -INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mink = min(mink, a[i]);
        maxk = max(maxk, a[i]);
    }
    if (k == 1) {
        cout << mink;
    } else if (k == 2) {
        cout << max(a[0], a[n - 1]);
    } else {
        cout << maxk;
    }
}