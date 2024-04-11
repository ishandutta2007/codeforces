#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    string s;
    cin >> s;
    vector<int> cnt(30);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    reverse(all(s));
    while (cnt[s.back() - 'a'] != 1) {
        cnt[s.back() - 'a']--;
        s.pop_back();
    }
    reverse(all(s));
    cout << s << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}