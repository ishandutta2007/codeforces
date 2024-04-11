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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> next(n, n);
    vector<int> good(n);
    vector<int> dp(n + 1);
    vector<map<int, int>> find(n + 1);
    for (int l = n - 1; l >= 0; --l) {
        find[l][a[l]] = l;
        int p = find[l+1][a[l]];
        if (p) {
            good[l] = 1;
            next[l] = p;
            if (p + 1 != n) {
                find[l] = move(find[p + 1]);
                find[l][a[l]] = l;
            }
        }
    }
    long long res = 0;
    for (int i = n - 1; i >= 0; --i) {
        //cout << good[i] << ' ';
        if (good[i])
            dp[i] = dp[next[i] + 1] + 1;
        res += dp[i];
    }
    //cout << '\n';
    cout << res << '\n';
}
/*
int slv2(int n, vector<int> a) {
    int res = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r <= n; ++r) {
            vector<int> b;
            for (int i = l; i < r; ++i) {
                if (b.empty() or b.back() != a[i])
                    b.push_back(a[i]);
                else
                    b.pop_back();
            }
            if (b.empty())
                res++;
        }
    }
    return res;
}
void chk() {
    int n = rand() % 5 + 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % n + 1;
    }
    if (slv2(n, a) != solve(n, a)) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        cout << slv2(n, a) << ' ' << solve(n, a) << endl;
        exit(0);
    }
}
 */
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}