//    -
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<int> used(n + 1);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        int res = 0;
        while (!used[b]) {
            used[a.back()] = 1;
            a.pop_back();
            ++res;
        }
        cout << res << " ";
    }
    return 0;
}