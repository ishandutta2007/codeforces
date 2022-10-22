#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Box {
    int t, h;
};

bool operator<(Box a, Box b){
    if (a.t != b.t) {
        return a.t < b.t;
    }
    return a.h > b.h;
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
    int n, l, r;
    int sumh = 0;
    cin >> n >> l >> r;
    vector <Box> b(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        b[i].h = h;
        sumh += h;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].t;
    }
    r = sumh - r;
    l = sumh - l;
    swap(l, r);
    sort(b.begin(), b.end());
    vector <int> dp(sumh + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sumh; j >= 0; j--) {
            if (b[i].h + j > sumh) continue;
            dp[b[i].h + j] = max(dp[b[i].h + j], dp[j] + b[i].t * ((j + b[i].h >= l && j + b[i].h <= r) ? 1 : 0));
        }
    }
    int res = 0;
    for (int i = 0; i <= sumh; i++) {
        res = max(res, dp[i]);
    }
    cout << res;
}