#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(0));
struct Bit {
    vector<int> bit;
    Bit() {}
    Bit(int n) {
        bit.resize(n + 1);
        for (int i = 0; i <= n; i ++) bit[i] = 0;
    }
    void add(int x, int y) {
        while (x < (int)bit.size()) {
            bit[x] += y; x += x & (-x);
        }
    }
    int query(int x) {
        int ans = 0;
        while (x > 0) {
            ans += bit[x]; x -= x & (-x);
        }
        return ans;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    Bit b[62];
    constexpr int T = 40;
    for (int i = 0; i < T; i ++) {
        b[i] = Bit(n);
    }
    unordered_map<int, ll> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (! mp.count(a[i])) {
            ll tmp = 0;
            for (int j = 0; j < T; j ++) {
                if (rnd() % 2 == 0) tmp |= 1ll<<j;
            }
            mp[a[i]] = tmp;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < T; j ++) if (mp[a[i]] >> j & 1) {
            b[j].add(i, 1);
        }
    }
    while (q --){
        int op; 
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            for (int j = 0; j < T; j ++) if (mp[a[i]] >> j & 1) {
                b[j].add(i, -1);
            }
            
            a[i] = x;
            if (! mp.count(a[i])) {
                ll tmp = 0;
                for (int j = 0; j < T; j ++) {
                    if (rnd() % 2 == 0) tmp |= 1ll<<j;
                }
                mp[a[i]] = tmp;
            }
            for (int j = 0; j < T; j ++) if (mp[a[i]] >> j & 1) {
                b[j].add(i, +1);
            }
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            if (k == 1) {
                cout << "YES\n"; continue;
            }
            if ((r - l + 1) % k) {
                cout << "NO\n"; continue;
            }
            bool ok = true;
            for (int i = 0; i < T; i ++) {
                ok &= (b[i].query(l, r) % k == 0);
                if (not ok) break;
            }
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
}