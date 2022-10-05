#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int I = 1, J = 5, K = 11;
int lpere(pair<int, int> a, pair<int, int> b) {
    return max(0ll, 1 + min(a.second, b.second) - max(a.first, b.first));
}
int zpr(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    return x;
}
int findx(int a) {
    int x = sqrt(1 + 2 * a);
    //cout << x << endl;
    while (x * (x - 1) / 2 < a)
        x++;
    while (x * (x - 1) / 2 > a)
        x--;
    return x;
}
void solve(){
    int n = 50000;
    cin >> n;
    int l = 1;
    int r = n;
    int sum = zpr(l, r);
    int i = -1, k = -1;
    while (l + 1 < r) {
        int m = l + r >> 1;
        //cout << l << ' ' << r << endl;
        //cout << i << ' ' << k << endl;
        //cout << m << endl;
        if (k != -1) {
            int val = zpr(m, n);
            int x = findx(val);
            //cout << val << ' ' << x << ' ' << k - m << endl;
            if ((x * (x - 1) / 2 == val and x == k - m + 1) or val == 0) {
                r = m;
            }  else {
                l = m;
            }
        } else if (i != -1) {
            int val = zpr(1, m);
            int x = findx(val);
            if ((x * (x - 1) / 2 == val and x == m - i + 1) or val == 0) {
                l = m;
            } else {
                r = m;
            }
        } else {
            int val = zpr(1, m);
            int x = findx(val);
            if (x * (x - 1) / 2 == val) {
                if (val == sum) {
                    r = m;
                    continue;
                }
                if (val == 0) {
                    l = m;
                    continue;
                }
                int y = zpr(m-x+1, m);
                //cout << val << ' ' << y << "!!!" << endl;
                if (val == y) {
                    i = m - x + 1;
                    l = m;
                } else {
                    int val2 = zpr(m + 1, n);
                    k = findx(val2) + m;
                    //cout << m << ' ' << val2 << ' ' << k << endl;
                    r = m;
                }
            } else {
                r = m;
            }
        }
    }
    int t = zpr(1, l);
    i = r-findx(t);k = r + findx(zpr(r, n)) - 1;
    cout << "! " << i << ' ' << r << ' ' << k << endl;
}
signed main() {
    //solve();
    //ios_base::sync_with_stdio(0);
    //cout << findx(3299239329329302203ll);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}
//1 5 2 1 1 0 0