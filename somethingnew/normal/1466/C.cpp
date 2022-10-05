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
void solve(){
    string s;
    cin >> s;
    int res = 0;
    int i = 2;
    if (s[0] == s[1]) {
        res = 1;
        s[1] = 'A';
    }
    for (; i < s.size(); ++i) {
        if (s[i] == s[i - 1] or s[i] == s[i-2]) {
            res++;
            s[i] = 'A';
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}