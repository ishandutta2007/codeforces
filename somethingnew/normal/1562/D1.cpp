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
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> prefsum(n + 1);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            prefsum[i + 1] = (s[i] == '+') + prefsum[i];
        else
            prefsum[i + 1] = -(s[i] == '+') + prefsum[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int r1 = prefsum[r] - prefsum[l];
        int an = 0;
        if (r1) {
            an++;
            l++;
        }
        if ((r - l) % 2) {
            an++;
        }
        cout << an << '\n';
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