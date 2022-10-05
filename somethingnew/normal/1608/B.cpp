#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(a) (a).begin(), (a).end()
#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n);
    int swp = 0;
    if (a < b) {
        swp = 1;
        swap(a, b);
    }
    int mn = 2, mx = n;
    ans[0] = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (ans[i - 1] < mx and a != 0) {
            ans[i] = mx;
            mx--;
            a--;
        } else if (ans[i - 1] > mn and b != 0) {
            ans[i] = mn;
            mn++;
            b--;
        } else {
            if (ans[i - 1] < mn) {
                ans[i] = mn;
                mn++;
            } else {
                ans[i] = mx;
                mx--;
            }
        }
    }
    if (a != 0 or b != 0) {
        cout << "-1\n";
        return;
    }
    ans.back() = mx;
    for (auto i : ans) {
        if (swp)
            i = n - i + 1;
        cout << i << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}