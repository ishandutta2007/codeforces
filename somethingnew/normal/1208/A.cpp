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
    int a, b, n;
    cin >> a >> b >> n;
    n %= 3;
    if (n == 0)
        cout << a << '\n';
    else if (n == 1)
        cout << b << '\n';
    else
        cout << (a ^ b) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}