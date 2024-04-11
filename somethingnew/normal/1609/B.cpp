#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
string s;
bool right(int ind) {
    if (s[ind] == 'a') {
        if (s[ind + 1] == 'b' and s[ind + 2] == 'c')
            return 1;
        return 0;
    }
    if (s[ind] == 'b' and ind > 0) {
        if (s[ind + 1] == 'c' and s[ind - 1] == 'a')
            return 1;
        return 0;
    }
    if (s[ind] == 'c' and ind > 1) {
        if (s[ind - 1] == 'b' and s[ind - 2] == 'a')
            return 1;
        return 0;
    }
    return 0;
}
void solve() {
    int n, q;
    cin >> n >> q;
    int res = 0;
    cin >> s;
    s.push_back('?');
    s.push_back('?');
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'c')
            res += right(i);
    }
    for (int i = 0; i < q; ++i) {
        int ind;
        cin >> ind;ind--;
        char c;
        cin >> c;
        res -= right(ind);
        s[ind] = c;
        res += right(ind);
        cout << res << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n = 1;
    while (n--)
        solve();
}