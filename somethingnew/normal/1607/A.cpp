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
    map<char, int> mp;
    string s;
    cin >> s;
    for (int i = 0; i < 26; ++i) {
        mp[s[i]] = i;
    }
    int res = 0;
    cin >> s;
    for (int j = 0; j + 1 < s.size(); ++j) {
        res += abs(mp[s[j]] - mp[s[j + 1]]);
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