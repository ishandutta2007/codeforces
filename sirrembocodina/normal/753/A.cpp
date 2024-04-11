#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

#define int long long

int32_t main() {
    //freopen("notation.in", "r", stdin);
    //freopen("notation.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; ; i++) {
        if ((i + 2) * (i + 1) / 2 > n) {
            cout << i << endl;
            for (int j = 1; j < i; j++) {
                cout << j << " ";
            }
            cout << n - (i - 1) * i / 2 << endl;
            return 0;
        }
    }
    return 0;
}