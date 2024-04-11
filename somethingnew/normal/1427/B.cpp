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
#define int long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int wcounter = 0;
    vector<int> d;
    int dir = 0;
    bool fw = true;
    for (auto i : s) {
        if (i == 'W'){
            if(fw)
                dir = 0;
            fw = false;
            wcounter += 1;
            if(dir != 0)
                d.push_back(dir);
            dir = 0;
        }else
            dir++;
    }
    wcounter = min(wcounter + k, n);
    sort(d.rbegin(), d.rend());
    while(k > 0 and !d.empty()){
        if(d.back() > k)
            break;
        k -= d.back();
        d.pop_back();
    }
    cout << max(wcounter * 2 - 1 - (int)d.size(), 0ll) << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}