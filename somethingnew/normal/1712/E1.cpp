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

struct segtree{
    vector<long long> tree;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz <= n)
            sz *= 2;
        tree.assign(sz * 2, 0);
    }
    long long segsum(int l, int r) {
        l += sz;
        r += sz;
        long long res = 0;
        while (l <= r) {
            if (l & 1) {
                res += tree[l];
                l++;
            }
            if ((r & 1) == 0) {
                res += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
    void ch(int v, int dx) {
        v += sz;
        while (v) {
            tree[v] += dx;
            v /= 2;
        }
    }
};
int max_n = 2e5 + 5;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    /*
    for (int i = 1; i < 1000; ++i) {
        for (int j = i + 1; j < 1000; ++j) {
            for (int k = j + 1; k < 1000; ++k) {
                if (lcm(lcm(i, j), lcm(j, k)) < i + j + k) {
                    if (k % i != 0 or k % j != 0) {
                        if (gcd(i, gcd(j, k)) == 1) {
                            cout << i << ' ' << j << ' ' << k << endl;
                        }
                    }
                }
            }
        }
    }*/
    cin >> t;
    vector<array<int, 3>> zpr;
    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        zpr.push_back({l, i, r});
    }
    sort(all(zpr));
    vector<int> delcnt(max_n);
    for (int i = 1; i < max_n; ++i) {
        for (int j = 2 * i; j < max_n; j += i) {
            delcnt[j]++;
        }
    }
    segtree sg;
    sg.init(max_n);
    for (int i = 1; i < max_n; ++i) {
        sg.ch(i, (delcnt[i] * delcnt[i] - delcnt[i]) / 2 + (i % 3 == 0 and i % 2 == 0) + (i % 3 == 0 and i % 5 == 0));
    }
    vector<long long> ans(t);
    int gll = 1;
    for (auto [l, i, r] : zpr) {
        while (gll < l) {
            if (gll * 2 < max_n and gll % 3 == 0) {
                sg.ch(gll * 2, -1);
                //cerr << gll * 2 << '\n';
            }
            if (gll % 2 == 0 and gll / 2 * 5 < max_n and gll % 3 == 0) {
                sg.ch(gll / 2 * 5, -1);
                //cerr << gll / 2 * 5 << '\n';
            }
            for (int j = 2 * gll; j < max_n; j += gll) {
                sg.ch(j, -(delcnt[j] * delcnt[j] - delcnt[j]) / 2);
                delcnt[j]--;
                sg.ch(j, (delcnt[j] * delcnt[j] - delcnt[j]) / 2);
            }
            gll++;
        }
        //cout << sg.segsum(l, l) << ' ' << sg.segsum(l + 1, l + 1) << sg.segsum(l + 2, l +2) << ' ' << sg.segsum(l + 3, l + 3) << '\n';
        long long len = r - l + 1;
        long long res = len * (len - 1) * (len - 2) / 6;
        ans[i] = res - sg.segsum(l, r);
    }
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << '\n';
    }
}