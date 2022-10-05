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
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    set<int> res;
    int c1 = (a + b) / 2;
    int c2 = (a + b) - c1;
    int bd = c1 - a;
    for (int i = 0; i <= a; ++i) {
        res.insert(bd + i * 2);
    }
    swap(c1, c2);
    bd = c1 - a;
    for (int i = 0; i <= a; ++i) {
        res.insert(bd + i * 2);
    }
    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}