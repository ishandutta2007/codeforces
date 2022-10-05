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
struct dsu{
    vector<int> p;
    int cnt;
    void init(int n) {
        p.assign(n, {});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        cnt = n;
    }
    int getv(int v) {
        if (p[v] == v) return v;
        return p[v] = getv(p[v]);
    }
    bool mrg(int a, int b) {
        //cout << a << ' ' << b << endl;
        a = getv(a);
        b = getv(b);
        if (a != b) {
            p[a] = b;
            cnt--;
            return 1;
        }
        return 0;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> gdind(30, -1);
    dsu ds;
    ds.init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) {
                if (gdind[j] != -1)
                    ds.mrg(i, gdind[j]);
                gdind[j] = i;
            }
        }
    }
    if (ds.cnt != 1) {
        vector<int> c = a;
        vector<int> b = a;
        int bval = ds.cnt - 1 + (gdind[0] == -1);
        for (int i = 0; i < n; ++i) {
            if (gdind[0] == -1) {
                gdind[0] = i;
                b[i]++;
            }
            if (ds.mrg(gdind[0], i)) {
                b[i]++;
            }
        }
        for (int q = 0; q < n; ++q) {
            a = c;
            int p = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i]) {
                    if (i == q) {
                        p = i;
                    }
                }
            }
            if (p != -1) {
                int vl = 1;
                a[p]--;
                vector<int> gdind(30, -1);
                dsu ds;
                ds.init(n);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < 30; j++) {
                        if (a[i] & (1 << j)) {
                            if (gdind[j] != -1)
                                ds.mrg(i, gdind[j]);
                            gdind[j] = i;
                        }
                    }
                }
                vl += ds.cnt - 1;
                for (int i = 0; i < n; ++i) {
                    if (gdind[0] == -1) {
                        gdind[0] = i;
                        a[i]++;
                    }
                    if (ds.mrg(gdind[0], i)) {
                        a[i]++;
                    }
                }
                if (vl < bval) {
                    bval = vl;
                    b = a;
                }
            }
        }
        cout << bval << '\n';
        for (auto i : b)
            cout << i << ' ';
    } else {
        cout << "0\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
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