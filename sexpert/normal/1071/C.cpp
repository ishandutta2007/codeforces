#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
vector<vector<array<int, 3>>> lmao(64);
const int NUFF = 11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    v.resize(n);

    for(auto &x : v)
        cin >> x;

    vector<array<int, 3>> ops;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; 2 * j - i < NUFF; j++) {
            ops.push_back({i, j, 2*j - i});
        }
    }
    int sz = ops.size();
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            int res = 0;
            for(int x : ops[i])
                res ^= (1 << x);
            for(int x : ops[j])
                res ^= (1 << x);
            lmao[res & 63] = {ops[i], ops[j]};
        }
    }

    for(int i = 0; i < sz; i++) {
        int res = 0;
        for(int x : ops[i])
            res ^= (1 << x);
        lmao[res & 63] = {ops[i]};
    }

    lmao[0] = {};

    /*for(int i = 0; i < 63; i++) {
        cout << i << ": ";
        for(auto &[a, b, c] : lmao[i]) {
            cout << "{" << a << ", " << b << ", " << c << "} ";
        }
        cout << '\n';
    }*/

    vector<array<int, 3>> ans;

    if(n <= 10) {
        if(accumulate(v.begin(), v.end(), 0) == 0) {
            cout << "YES\n0\n";
            return 0;
        }
        vector<array<int, 3>> ps;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; 2 * j - i < n; j++) {
                ps.push_back({i, j, 2*j - i});
            }
        }
        int tar = 0;
        for(int i = 0; i < n; i++)
            tar += (v[i] << i);
        int sz = ps.size();
        for(int bm = 0; bm < (1 << sz); bm++) {
            int res = 0;
            for(int b = 0; b < sz; b++) {
                if(bm & (1 << b)) {
                    for(auto x : ps[b])
                        res ^= (1 << x);
                }
            }
            if(res == tar) {
                cout << "YES\n";
                cout << __builtin_popcount(bm) << '\n';
                for(int b = 0; b < sz; b++) {
                    if(bm & (1 << b)) {
                        auto &[x, y, z] = ps[b];
                        cout << x + 1 << " " << y + 1 << " " << z + 1 << '\n';
                    }
                }
                return 0;
            }
        }
        cout << "NO\n";
        return 0;
    }

    int ps = 0;
    while(ps + 11 < n) {
        int req = v[ps] + 2*v[ps + 1] + 4*v[ps + 2] + 8*v[ps + 3] + 16*v[ps + 4] + 32*v[ps + 5];
        auto tris = lmao[req];
        for(auto &[x, y, z] : tris) {
            v[ps + x] ^= 1;
            v[ps + y] ^= 1;
            v[ps + z] ^= 1;
            ans.push_back({ps + x + 1, ps + y + 1, ps + z + 1});
        }

        ps += 6;
    }

    //for(auto x : v)
    //    cout << x << " ";
    //cout << endl;

    int m = n - 11;
    int tar = 0;
    for(int j = 0; j < 11; j++)
        tar += (v[m + j] << j);
    vector<array<int, 3>> po;
    for(int i = 0; i < 11; i++) {
        for(int j = i + 1; 2*j - i < 11; j++) {
            po.push_back({i, j, 2*j - i});
        }
    }
    sz = po.size();
    //cout << tar << endl;
    //cout << sz << endl;
    for(int bm = 0; bm < (1 << sz); bm++) {
        int res = 0;
        for(int b = 0; b < sz; b++) {
            if(bm & (1 << b)) {
                for(auto x : po[b])
                    res ^= (1 << x);
            }
        }
        if(res == tar) {
            for(int b = 0; b < sz; b++) {
                if(bm & (1 << b)) {
                    auto &[x, y, z] = po[b];
                    ans.push_back({m + x + 1, m + y + 1, m + z + 1});
                }
            }
            break;
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto &[a, b, c] : ans)
        cout << a << " " << b << " " << c << '\n';
}