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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(all(a));
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        if (s == x) {
            if (i == n - 1) {
                cout << "NO\n";
                return;
            }
            swap(a[i], a[i + 1]);
            break;
        }
    }
    cout << "YES\n";
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}