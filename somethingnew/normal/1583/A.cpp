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
bool isprime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    int res = 0;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 1)
            ind = i;
        res += x;
    }
    if (isprime(res)) {
        cout << n - 1 << '\n';
        for (int i = 0; i < n; ++i) {
            if (ind != i)
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
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