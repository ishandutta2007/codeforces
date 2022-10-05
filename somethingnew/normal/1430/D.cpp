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

using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> lst;
    char lel = s[0];
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        if(lel == s[i]) {
            sz++;
        }
        else{
            lel = s[i];
            lst.push_back(sz);
            sz = 1;
        }
    }
    lst.push_back(sz);
    int ans = 0;
    for (int i = 0; i < lst.size(); ++i) {
        ans = min(ans + lst[i] - 1, i + 1);
    }
    cout << min(ans + ((int)lst.size() - ans + 1) / 2, (int)lst.size()) << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}