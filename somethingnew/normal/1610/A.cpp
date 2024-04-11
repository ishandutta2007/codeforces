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
    if (n == 1 and m == 1) {
        cout << "0\n";
        return;
    }
    if (n == 1 or m == 1) {
        cout << "1\n";
        return;
    }
    cout << "2\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}