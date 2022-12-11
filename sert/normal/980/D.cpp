#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

inline int cutN(int x) {
    if (x == 0) return 0;
    if (x < 0) return -cutN(-x);
    int res = 1;
    int xx = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        int num = 0;
        while (xx % i == 0) {
            xx /= i;
            num++;
        }
        if (num & 1) res *= i;
    }
    if (xx > 1) res *= xx;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace_back(cutN(x), i);
    }
    sort(a.begin(), a.end());
    int lst = a[0].first;
    int zero = -1;
    if (a[0].first == 0) zero = 0;
    a[0] = {a[0].second, 0};
    for (int i = 1; i < n; i++) {
        if (a[i].first == lst) {
            if (a[i].first == 0) zero = a[i - 1].second;
            a[i] = {a[i].second, a[i - 1].second};
        } else {
            lst = a[i].first;
            if (a[i].first == 0) zero = a[i - 1].second + 1;
            a[i] = {a[i].second, a[i - 1].second + 1};
        }
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 0; i < n; i++) b.push_back(a[i].second);
    vector<int> u(n, -1);
    int kk = 0;

    vector<int> ans(n + 1, 0);
    for (int st = 0; st < n; st++) {
        kk++;
        int dif = 0;
        bool is0 = false;
        for (int i = st; i < n; i++) {
            if (u[b[i]] != kk && b[i] != zero) {
                u[b[i]] = kk;
                dif++;
            }
            ans[max(1, dif)]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    //solve();
    //solve();
    solve();
    return 0;
}