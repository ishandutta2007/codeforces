#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#define all(a) (a).begin(), (a).end()
using namespace std;
void solve() {
    string s, t;
    cin >> s >> t;
    string s2;
    int ccount = 0, bcount = 0, acount = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'b')
            bcount++;
        else if (s[i] == 'c')
            ccount++;
        else if (s[i] == 'a')
            acount++;
        else
            s2.push_back(s[i]);
    }
    sort(all(s2));
    if (t == "abc" and acount != 0) {
        for (int i = 0; i < acount; ++i) {
            cout << 'a';
        }
        for (int i = 0; i < ccount; ++i) {
            cout << 'c';
        }
        for (int i = 0; i < bcount; ++i) {
            cout << 'b';
        }
        cout << s2 << '\n';
    } else {
        sort(all(s));
        cout << s << '\n';
    }

}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}
/*
1 2
RL
DU
LR
10
v 1 1
v 1 2
v 1 3
v 2 1
v 2 2
v 2 3
h 1 1
h 2 1
h 3 1
h 4 1

 */