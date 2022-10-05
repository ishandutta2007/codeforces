#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include "fstream"
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"

#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
signed main() {
    int n;
    cin >> n;
    vector<int> ans;
    int p = 1;
    for (int i = 1; i < n; ++i) {
        if (gcd(i, n) == 1) {
            p *= i;
            p %= n;
            ans.push_back(i);
        }
    }
    if (p == 1) {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i << ' ';
    } else {
        cout << ans.size() - 1 << endl;
        for (auto i : ans) {
            if (p == i) {
                p = 0;
                continue;
            }
            cout << i << ' ';
        }
    }
}