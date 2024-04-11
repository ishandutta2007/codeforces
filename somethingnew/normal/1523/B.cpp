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
void slv(int a, int b) {
    cout << "1 " << a << ' ' << b << '\n';
    cout << "2 " << a << ' ' << b << '\n';
    cout << "1 " << a << ' ' << b << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & i : a)
        cin >> i;
    cout << n * 3 << '\n';
    for (int i = 0; i < n; i += 2) {
        slv(i + 1, i + 2);
        slv(i + 1, i + 2);
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