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
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(all(a));
    sort(all(b));
    vector<int> c;
    for (int i = 0; i < b.size(); ++i) {
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    if (n % 2)
        c.push_back(a.back());
    vector<int> d = c;
    sort(all(d));
    if (c != d) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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