#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
void solve() {
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sm += x;
    }
    if (sm % n == 0)
        cout << "0\n";
    else
        cout << "1\n";
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}