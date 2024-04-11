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
    int c, d;
    cin >> c >> d;
    if (abs(c) % 2 != abs(d) % 2) {
        cout << "-1\n";
    } else if (0 == c and 0 == d) {
        cout << "0\n";
    } else if (abs(c) == abs(d)) {
        cout << "1\n";
    } else {
        cout << "2\n";
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