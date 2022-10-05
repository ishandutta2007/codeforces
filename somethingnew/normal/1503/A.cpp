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
bool goods(string s) {
    int b = 0;
    for (auto i : s) {
        if (i == '(')
            b++;
        else
            b--;
        if (b < 0)
            return false;
    }
    return b == 0;
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1, s2;
    int cnt1 = 0, cnt0 = 0;
    for (auto i : s) {
        if (i == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 % 2 or cnt1 % 2) {
        cout << "NO\n";
        return;
    }
    int c0 = 0, c1 = cnt1 / 2;
    for (auto i : s) {
        if (i == '1') {
            if (c1 > 0) {
                s1.push_back('(');
                s2.push_back('(');
            } else {
                s1.push_back(')');
                s2.push_back(')');
            }
            c1--;
        } else {
            if (c0 % 2) {
                s1.push_back('(');
                s2.push_back(')');
            } else {
                s1.push_back(')');
                s2.push_back('(');
            }
            c0--;
        }
    }
    if (goods(s1) and goods(s2)) {
        cout << "YES\n" << s1 << '\n' << s2 << '\n';
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}