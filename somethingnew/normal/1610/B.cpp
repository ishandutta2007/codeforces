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
bool poli(vector<int> s, int x) {
    vector<int> s2, s3;
    for (auto i : s) {
        if (i != x)
            s2.push_back(i);
    }
    s3 = s2;
    reverse(all(s3));
    return s3 == s2;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[n-1-i]) {
            if (poli(a, a[i]) or poli(a, a[n-1-i])) {
                cout << "YES\n";
                return;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}