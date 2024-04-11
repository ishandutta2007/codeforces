#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
void solve() {
    int n, k;
    cin >> n >> k;
    int t = k - 3;
    n -= t;
    if (n % 2 == 1){
        cout << n / 2 << ' ' << n / 2 << ' ' << ' ' << 1 << ' ';
    } else if (n % 4 == 2){
        cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << ' ';
    } else {
        cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << ' ';
    }
    for (int i = 0; i < t; ++i) {
        cout << 1 << ' ';
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}