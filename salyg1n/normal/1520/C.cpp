#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        int l = 1, r = 1 + (n * n + 1) / 2;
        int num = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (num % 2 == 0) {
                    cout << l << " ";
                    l++;
                }
                else {
                    cout << r << " ";
                    r++;
                }
                num++;
            }
            cout << "\n";
        }
    }
    return 0;
}