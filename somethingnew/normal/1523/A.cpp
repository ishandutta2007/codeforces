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
string evolve(string s) {
    string s2 = s;
    for (int i = 1; i + 1 < s2.size(); ++i) {
        if ((s[i-1] == '1') + (int)(s[i + 1] == '1') == 1) {
            s2[i] = '1';
        }
    }
    if (s[1] == '1')
        s2[0] = '1';
    if (s[s.size() - 2] == '1')
        s2.back() = '1';
    return s2;
}
void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    m = min(m, n);
    for (int i = 0; i < m; ++i) {
        s = evolve(s);
    }
    cout << s << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}