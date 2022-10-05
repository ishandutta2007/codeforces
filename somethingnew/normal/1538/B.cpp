#include "list"
#include <iostream>
#include "queue"
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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (auto &i : a) {
        cin >> i;
        s += i;
    }
    if (s % n != 0) {
        cout << -1 << '\n';
        return;
    }
    s /= n;
    int k = 0;
    for (auto i : a)
        if (i > s)
            k++;
        cout << k << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}