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
    long long n;
    cin >> n;
    if (n % 2050) {
        cout << "-1\n";
        return;
    }
    n /= 2050;
    int res = 0;
    long long q = 1e18;
    while (q) {
        while (n >= q) {
            res++;
            n -= q;
        }
        q /= 10;
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}