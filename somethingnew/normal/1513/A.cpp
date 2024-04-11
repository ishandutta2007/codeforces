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
    int n, k;
    cin >> n >> k;
    int nk = k * 2 + 1;
    if (nk > n) {
        cout << "-1\n";
        return;
    }
    vector<int> a(nk);
    for (int i = 0; i < nk / 2 + 1; ++i) {
        a[i * 2] = i + 1;
    }
    for (int i = 0; i < nk / 2; ++i) {
        a[i * 2 + 1] = i + nk / 2 + 2;
    }
    for (auto i : a)
        cout << i << ' ';
    for (int i = nk + 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}