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
bool prime(int x) {
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
void solve(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        if (!prime(s[i] - '0')){
            cout << 1 << '\n';
            cout << s[i] << '\n';
            return;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            if (!prime((s[j] - '0') * 10 + s[i] - '0')) {
                cout << 2 << '\n';
                cout << s[j] << s[i] << '\n';
                return;
            }
        }
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