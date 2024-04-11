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
    if (n % 2 == 1){
        cout << n / 2 << ' ' << n / 2 << ' ' << ' ' << 1 << endl;
    } else if (n % 4 == 2){
        cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << endl;
    } else {
        cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}