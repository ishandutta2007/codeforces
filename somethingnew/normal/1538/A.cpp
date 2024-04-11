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
    int minp = 0, maxp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > a[maxp])
            maxp = i;
        if (a[i] < a[minp])
            minp = i;
    }
    if (minp > maxp)
        swap(minp, maxp);
    cout << min(n - minp, min(maxp + 1, minp + 1 + n - maxp)) << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}