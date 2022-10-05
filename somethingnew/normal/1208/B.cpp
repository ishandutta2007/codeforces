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
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    map<int, int> first, last;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (first[a[i]] == 0)
            first[a[i]] = i + 1;
        else
            k = 1;
        last[a[i]] = i;
    }
    for (auto &i : first)
        i.second--;
    if (k == 0) {
        cout << "0\n";
        return 0;
    }
    int ans = n;
    for (int l = 0; l < n; ++l) {
        for (int r = n - 1; r >= l; --r) {
            ans = min(ans, r - l + 1);
            if (first[a[r]] < l)
                break;
            if (last[a[r]] != r)
                break;
        }
        if (first[a[l]] != l)
            break;
    }
    cout << ans;
}