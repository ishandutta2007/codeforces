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
int slv(vector<int> a) {
    int ind = 0;
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 1) {
            if (ind >= a.size())
                return -1;
            res += abs(ind - i);
            ind += 2;
        }
    }
    if (ind < a.size())
        return -1;
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 2;
    }
    int r1 = slv(a);
    for (auto &i : a)
        i = 1 - i;
    int r2 = slv(a);
    if (r1 == -1)
        r1 = r2;
    if (r2 != -1)
        r1 = min(r1, r2);
    cout << r1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}