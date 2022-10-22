#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Tree {
    int n;
    vector <int> t;
    Tree(int n) : n(n), t(2 * n, 0) {}
    void change(int v, int x) {
        v += n;
        t[v] = x;
        v /= 2;
        while (v) {
            t[v] = max(t[2 * v], t[2 * v + 1]);
            v /= 2;
        }
    }
    int get_max(int l, int r) {
        int res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) res = max(res, t[l++]);
            if (r % 2 == 0) res = max(res, t[r--]);
        }
        return res;
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    vector <int> cnt(m, 0);
    vector <pair <int, int> > a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        a.push_back({l, 1});
        a.push_back({r + 1, 0});
    }
    sort(a.begin(), a.end());
    int pr = 0;
    int now = 0;
    for (int i = 0; i < a.size(); i++) {
        while (a[i].first > pr) {
            cnt[pr] = now;
            pr++;
        }
        if (a[i].second) {
            now++;
        } else {
            now--;
        }
    }
    while (m > pr) {
        cnt[pr] = now;
        pr++;
    }
    vector <int> down(m, 0), up(m, 0);
    Tree t(n + 1);
    for (int i = m - 1; i >= 0; i--) {
        int val = t.get_max(0, cnt[i]) + 1;
        down[i] = val;
        t.change(cnt[i], val);
    }
    t = Tree(n + 1);
    for (int i = 0; i < m; i++) {
        int val = t.get_max(0, cnt[i]) + 1;
        //cout << val << " ";
        up[i] = val;
        t.change(cnt[i], val);
    }
    //cout << "\n";
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = max(res, up[i] + down[i] - 1);
    }
    cout << res;
}