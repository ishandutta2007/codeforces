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
int zpr(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}
int zpr2(int c, int n) {
    string s(n, '0');
    s[c] = '1';
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}
void solve() {
    int n, stepa;
    cin >> stepa >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].second = i;
        a[i].first = zpr2(i, n);
    }
    sort(all(a));
    int res = 0;
    string s(n, '0');
    for (int i = 0; i < s.size(); ++i) {
        s[a[i].second] = '1';
        int val2 = zpr(s);
        if (res + a[i].first == val2) {
            res += a[i].first;
        } else {
            s[a[i].second] = '0';
        }
    }
    cout << "! " << res << endl;
}
signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
}