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
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0;
        return;
    }
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            res *= abs(a[i] - a[j]);
            res %= m;
        }
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}