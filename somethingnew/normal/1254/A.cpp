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
    int n, m, k;
    cin >> n >> m >> k;
    string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    vector<string> pole(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pole[i];
        for (auto j : pole[i])
            if (j == 'R')
                cnt++;
        if (i % 2)
            reverse(all(pole[i]));
    }
    vector<string> ans = pole;
    int pk = 0;
    int t1 = cnt / k;
    int t2 = cnt % k;
    int targ = t1 + (t2 != 0);
    if (t2 != 0)
        t2--;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = alph[pk];
            if (pole[i][j] == 'R')
                targ--;
            if (targ == 0) {
                pk++;
                if (pk == k)
                    pk--;
                targ = t1 + (t2 != 0);
                if (t2 != 0)
                    t2--;
            }
        }
        if (i % 2)
            reverse(all(ans[i]));
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
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