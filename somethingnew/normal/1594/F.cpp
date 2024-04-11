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
void solve(){
    int s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
        cout << "YES\n";
        return;
    }
    int ab = k + 1;
    int abc = n / k;
    int res = abc * ab + (n - abc);
    if (res <= s) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}