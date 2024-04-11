//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int md = 1e9 + 7;
vector<int> div(int x) {
    vector<int> dv = {1};
    for (int i = 2; i * i <= x; ++i) {
        int k = 0;
        while (x % i == 0) {
            k++;
            x /= i;
        }
        int q = dv.size();
        int ip = 1;
        for (int j = 1; j <= k; ++j) {
            ip *= i;
            for (int l = 0; l < q; ++l) {
                dv.push_back(dv[l] * ip);
            }
        }
    }
    if (x == 1)return dv;
    int i = x;
    int k = 0;
    while (x % i == 0) {
        k++;
        x /= i;
    }
    int q = dv.size();
    int ip = 1;
    for (int j = 1; j <= k; ++j) {
        ip *= i;
        for (int l = 0; l < q; ++l) {
            dv.push_back(dv[l] * ip);
        }
    }
    return dv;
}
#define ll long long
void solve() {
    int b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;
    ll res = 0;
    if ((c - b) % q != 0 or c < b or q > r) {
        cout << 0 << '\n';
        return;
    }
    if (c + r * z - r > b + q * y - q) {
        cout << 0 << '\n';
        return;
    }
    int inf = 0;
    for (auto shag : div(r)) {
        if ((long long)q * shag / gcd(q, shag) == r) {
            //cout << shag << endl;
            ll elm = q / gcd(q, shag);
            ll x = (c - b) / r;
            if (x == 0) {
                inf = 1;
                break;
            }
            ll opt;
            x = (b + q * y - q - (c + r * z - r)) / r;
            if (x == 0) {
                inf = 1;
                break;
            }
            opt = elm * elm;
            //cout << opt << endl;
            res += opt;
            res %= md;
        }
    }
    if (inf) {
        cout << "-1\n";
    } else {
        cout << res << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}