#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int root(int x) {
    if (p[x] == x) {
        return p[x];
    } else {
        return p[x] = root(p[x]);
    }
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
        return;
    }
    p[x] = y;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    int q;
    cin >> q;
    p.resize(n + q + q);
    iota(p.begin(), p.end(), 0);
    int sz = 0;
    map<long long, int> mp;
    map<int, long long> val;
    auto Add = [&](long long x) {
        if (mp.count(x)) {
            unite(sz, mp[x]);
        } else {
            mp[x] = sz;
            val[sz] = x;
        }
        sz++;
    };
    for (int i = 0; i < n; i++) {
        Add(a[i]);
    }
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, w;
            cin >> k >> w;
            k--;
            b[k] = sz;
            Add(w);
        } else if (op == 2) {
            int k;
            cin >> k;
            k--;
            k = root(b[k]);
            cout << val[k] << "\n";
        } else {
            long long l, r;
            cin >> l >> r;
            l--;
            r++;
            int lid = sz;
            Add(l);
            int rid = sz;
            Add(r);
            val[lid] = l;
            val[rid] = r;
            while (true) {
                auto iter = mp.lower_bound(l + 1);
                if (iter == mp.end()) {
                    break;
                }
                auto t = *iter;
                if (t.first >= r) {
                    break;
                }

                if (t.first <= (l + r) / 2) {
                    unite(t.second, lid);
                } else {
                    unite(t.second, rid);
                }
                mp.erase(iter);
            }
        }
    }
}