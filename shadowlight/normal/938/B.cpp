#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6;
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
    int mink = INF;
    int pr = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mink = min(mink, max(pr - 1, MAXN - x));
        pr = x;
    }
    mink = min(mink, pr - 1);
    cout << mink;
}