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
vector<int> a;
vector<int> dpupdown, dpdownup;
vector<int> goup, godown;
int n;
int chkseg(int l) {
    //
    int rfnd = 0;
    int p = godown[l];
    rfnd = max(p, rfnd);
    if (p == n - 1) {
        rfnd = max(rfnd, n-1);
    } else {
        rfnd = max(rfnd, dpdownup[p]);
        if (p != l) {
            rfnd = max(rfnd, dpdownup[p - 1]);
        }
    }
    p = goup[l];
    rfnd = max(p, rfnd);
    if (p == n - 1) {
        rfnd = max(rfnd, n-1);
    } else {
        rfnd = max(rfnd, dpupdown[p]);
        if (p != l) {
            rfnd = max(rfnd, dpupdown[p - 1]);
        }
    }
    return rfnd - l + 1;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    goup.assign(n, 0), godown.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        goup[i] = godown[i] = i;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1])
            goup[i] = goup[i + 1];
        if (a[i] > a[i + 1])
            godown[i] = godown[i + 1];
    }
    dpupdown.assign(n - 1, 0), dpdownup.assign(n - 1, 0);
    dpupdown.back() = n-1;
    dpdownup.back() = n-1;
    for (int i = n - 3; i >= 0; --i) {
        int p = godown[i + 1];
        dpupdown[i] = p;
        if (p == n - 1) {
            dpupdown[i] = n-1;
        } else {
            if (a[i] < a[p + 1]) {
                dpupdown[i] = dpdownup[p];
            }
            if (p != i + 1 and a[i] < a[p]) {
                dpupdown[i] = max(dpupdown[i], dpdownup[p - 1]);
            }
        }
        p = goup[i + 1];
        dpdownup[i] = p;
        if (p == n - 1) {
            dpdownup[i] = n-1;
        } else {
            if (a[i] > a[p + 1]) {
                dpdownup[i] = dpupdown[p];
            }
            if (p != i + 1 and a[i] > a[p]) {
                dpdownup[i] = max(dpdownup[i], dpupdown[p - 1]);
            }
        }
    }
    //exit(0);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += chkseg(i);
        //cout << chkseg(i) + i << '\n';
    }
    cout << sm << endl;
}