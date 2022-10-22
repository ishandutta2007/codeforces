#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 2000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

bool succ(const vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0 || (i > 0 && a[i] < a[i - 1])) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n, 0);
    
    while (succ(a) && m > 0) {
        --m; int p;
        cin >> p;
        if (p <= c / 2) {
            for (int i = 0; i < n; ++i) {
                if (p < a[i] || a[i] == 0) {
                    a[i] = p;
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
        else {
            for (int i = n - 1; i >= 0; --i) {
                if (p > a[i]) {
                    a[i] = p;
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}