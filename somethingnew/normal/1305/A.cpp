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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout<< '\n';
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout<< '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}