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
int MAXN = 2e6 + 303;
void solve() {
    int n;
    cin >> n;
    vector<int> a(MAXN);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    vector<int> nxtone(MAXN), prev(MAXN);
    prev[0] = -10000000;
    nxtone.back() = 4 * MAXN + 1;
    for (int i = 1; i < MAXN; ++i) {
        prev[i] = prev[i - 1];
        if (a[i])
            prev[i] = i;
    }
    for (int i = MAXN - 2; i >= 0; --i) {
        nxtone[i] = nxtone[i + 1];
        if (a[i])
            nxtone[i] = i;
    }
    for (int i = 1; i <= MAXN; ++i) {
        int l = -i, r = 0;
        int ind = nxtone[0];
        int k = i;
        while (ind < MAXN) {
            ind += k + 1;
            int pr, nx;
            if (ind >= MAXN)
                pr = prev.back();
            else
                pr = prev[ind-1];
            if (ind >= MAXN)
                nx = 4 * MAXN + 1;
            else
                nx = nxtone[ind];
            //cout << ' ' << i << ' ' << nx - ind - k << ' ' << pr - ind + 1 << endl;
            r = min(r, nx - ind - k);
            l = max(l, pr - ind + 1);
            ind += k;
            k += 1;
        }
        if (l <= r) {
            //cout << "MOGA" << i << ' ' << l << ' ' << r << endl;
            if (i * i - l - nxtone[0] >= 0) {
                for (int j = r; j >= l; --j) {
                    if (i * i - j - nxtone[0] >= 0) {
                        //cout << i << ' ' << l << ' ' << r << endl;
                        cout << i * i - j - nxtone[0] << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout << "BEBRA";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}