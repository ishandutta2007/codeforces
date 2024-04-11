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
    int n;
    cin >> n;
    if (n % 11 == 0) {
        cout << "YES\n";
        return;
    }
    for (int j = 0; j < 50; ++j) {
        n -= 111;
        if (n < 0) {
            cout << "NO\n";
            return;
        }
        if (n % 11 == 0) {
            cout << "YES\n";
            return;
        } 
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}