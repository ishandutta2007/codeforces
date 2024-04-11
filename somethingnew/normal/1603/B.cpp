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
    long long x, y, n;
    cin >> x >> y;
    if (x > y) {
        cout << x + y << '\n';
        return;
    }
    n = y / 2 + y / 2 / x * x;
    if (y / 2 / x * x == 0)
        n = (x + y) / 2;
    cout << n << '\n';
    //cout << (y / x * x + y) / 2 << '\n';

}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}