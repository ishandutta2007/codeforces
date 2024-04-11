#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct KK {
    vector<ll> v;
    KK(int sz) {
        v = vector<ll>(sz, 0);
    }
    void add(int l, int r, ll x) {
        // if (l != r) cout << "add " << l << " " << r << " " << x << endl;
        v[l] += x;
        if (r < (int)v.size()) v[r] -= x;
    }

    vector<ll> getAns() {
        vector<ll> res = {v[0]};
        for (int i = 1; i < (int)v.size(); i++) {
            res.push_back(res.back() + v[i]);
        }
        return res;
    }
};

struct SEG {
    int l, r, val;
    SEG (int l = 0, int r = 0, int val = 0): l(l), r(r), val(val) {}
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x--;
    }

    ll ans = 0;
    KK kk(n);

    for (int i = 0; i < n; i++) {
        int val = a[i];
        int pos = i;
        // cout << "val = " << val << " pos = " << pos << endl;
        ans += abs(i - a[i]);

        vector<SEG> segs = {SEG(0, val, -1), SEG(val, n - 1, 1), SEG(n - 1, n, val + val + 1 - n)};
        int dx = -pos;
        for (const auto seg : segs) {
            // cout << seg.l << " " << seg.r << " " << seg.val << " " << dx << endl;
            int l = seg.l + dx;
            int r = seg.r + dx;
            if (l < 0) kk.add(n + l, n + min(0, r), seg.val);
            //if (r >= n) kk.add(0, r - n, seg.val);
            if (r > 0) kk.add(max(l, 0), min(r, n), seg.val);
        }
    }
    auto dx = kk.getAns();
    // cout << "dx: ";
    // for (int x : dx) cout << x << " ";
    //     cout << endl;
    
    int pos = 0;
    ll cur = ans;
    for (int i = 0; i < n - 1; i++) {
        cur += dx[i];
        if (cur < ans) {
            ans = cur;
            pos = i + 1;
        }
    }
    cout << ans << " " << pos << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 3;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}