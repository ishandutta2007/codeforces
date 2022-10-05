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
#define int long long
using namespace std;
vector<int> ans;
bool ok;
void rev(vector<int> &a, int k) {
    reverse(a.begin(), a.begin() + k);
}
void slv(vector<int> a) {
    int n = a.size();
    if (n == 1)
        return;
    int nmp, np;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == n)
            np = i;
        if (a[i] == n - 1)
            nmp = i;
    }
    if (np % 2 == 1 or nmp % 2 == 0) {
        ok = 0;
        return;
    }
    ans.push_back(np + 1);
    rev(a, np + 1);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == n)
            np = i;
        if (a[i] == n - 1)
            nmp = i;
    }
    ans.push_back(nmp);
    rev(a, nmp);
    ans.push_back(nmp + 2);
    rev(a, nmp + 2);
    rev(a, 3);
    ans.push_back(3);
    rev(a, n);
    ans.push_back(n);
    a.pop_back();
    a.pop_back();
    return slv(a);
}
void solve(){
    ok = 1;
    ans.clear();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    slv(a);
    if (!ok)
        cout << -1;
    else {
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}