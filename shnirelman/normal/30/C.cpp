#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, t;
    long double p;

    Node() {};
};

int len2(Node a, Node b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool is(Node a, Node b) {
    long long dt = a.t - b.t;
    return dt * dt >= len2(a, b);
}

bool cmp(Node a, Node b) {
    return a.t < b.t;
}

int main() {
    int n;
    cin >> n;

    vector<Node> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
    }

    sort(a.begin(), a.end(), cmp);

    vector<long double> dp(n + 1, 0);
    long double ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(is(a[i], a[j])) {
                dp[i + 1] = max(dp[i + 1], dp[j + 1]);
            }
        }

        dp[i + 1] += a[i].p;
        ans = max(ans, dp[i + 1]);
    }

    cout << setprecision(20) << fixed << ans;
}