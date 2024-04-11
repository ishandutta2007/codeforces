#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double
using namespace std;

struct line {
    ld k, b;
};

struct point {
    ld x, y;
};

point intersec(line w1, line w2) {
    ld k1 = w1.k, b1 = w1.b;
    ld k2 = w2.k, b2 = w2.b;
    ld x = (b2 - b1) / (k1 - k2);
    ld y = k1 * x + b1;
    point ans; ans.x = x; ans.y = y;
    return ans;
}

vector<line> s;

void add_line(line p) {
    while (s.size() >= 2) {
        ld x1 = intersec(s[s.size() - 2], s[s.size() - 1]).x;
        ld x2 = intersec(s[s.size() - 2], p).x;
        if (x1 <= x2) {
            s.pop_back();
        } else {
            break;
        }
    }
    s.pb(p);
}

int my_lower_bound(int h) {
    int left = 0;
    int right = (int) s.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        point lol = intersec(s[mid - 1], s[mid]);
        if (lol.x < h) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return h * s[left].k + s[left].b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> D(n);
    vector<int> X(n), Y(n), A(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i] >> A[i];
        D[i] = {X[i], Y[i], A[i]};
    }
    sort(D.begin(), D.end());
    vector<int> dp(n);
    dp[0] = get<0> (D[0]) * get<1> (D[0]) - get<2> (D[0]);
    line d; d.k = -get<0> (D[0]); d.b = dp[0];
    add_line(d);
    for (int i = 1; i < n; i++) {
        int x = get<0> (D[i]), y = get<1> (D[i]), a = get<2> (D[i]);
        int num = x * y - a;
        dp[i] = max(dp[i], num);
        int je = my_lower_bound(y);
        dp[i] = max(dp[i], num + je);
        line d; d.k = -x; d.b = dp[i];
        add_line(d);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans;

}