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
    int l = 0, r = s.size() - 1;
    vector<int> ans;
    while (l < r) {
        if (s[l] == ')'){
            l++;
            continue;
        }
        if (s[r] == '(') {
            r--;
            continue;
        }
        ans.push_back(l);
        ans.push_back(r);
        l++;r--;
    }
    if (ans.size() == 0) {
        cout << 0;
        return;
    }
    cout << "1\n" << ans.size() << '\n';
    sort(all(ans));
    for (auto i : ans)
        cout << i + 1 << ' ';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}