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
    int n, a, b;
    cin >> n >> a >> b;
    long long res = 1;
    while (res <= n) {
        if (res % b == n % b) {
            cout << "Yes\n";
            return;
        }
        res *= a;
        if (a == 1)
        break;
    }
    cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}