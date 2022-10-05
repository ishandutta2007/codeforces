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
int slv(string s, char c) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] ==  '?')
            s[i] = c;
        c = (int)'B' + 'R' - c;
    }
    int r1 = 0;
    for (int j = 1; j < s.size(); ++j) {
        r1 += (s[j] == s[j-1]);
    }
    return r1;
}
string st(string s, char c) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] ==  '?')
            s[i] = c;
        c = (int)'B' + 'R' - c;
    }
    int r1 = 0;
    for (int j = 1; j < s.size(); ++j) {
        r1 += (s[j] == s[j-1]);
    }
    return s;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2;
    int res = 0;
    string ans;
    for (auto i : s) {
        if (i != '?') {
            s2.push_back(i);
            if (slv(s2, 'B') < slv(s2, 'R')) {
                ans += st(s2, 'B');
            } else {
                ans += st(s2, 'R');
            }
            ans.pop_back();
            s2 = i;
        } else {
            s2.push_back(i);
        }
    }
    if (slv(s2, 'B') < slv(s2, 'R')) {
        ans += st(s2, 'B');
    } else {
        ans += st(s2, 'R');
    }
    cout << ans << '\n';
    //res += min(slv(s2, 'B'), slv(s2, 'R'));
    //cout << res;

}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}