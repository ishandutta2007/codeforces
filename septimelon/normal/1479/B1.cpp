#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int query(int i, int n) {
    if (i < 1 || i >= n) {
        return INF;
    }
    int ans;
    cout << "? " << i << endl;
    cin >> ans;
    return ans;
}

bool dec(int i, int n) {
    int ql = query(i, n);
    int qr = query(i + 1, n);
    return ql > qr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    a[0] = 0;
    int cot = 0;
    int lasa = 0, lasb = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> nexts(n + 1, 0);
    for (int i = n - 2; i > 0; --i) {
        if (a[i + 1] == a[i + 2]) {
            nexts[i] = a[i + 1];
        }
        else {
            nexts[i] = nexts[i + 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (lasa == nexts[i] && lasa != a[i]) {
            lasa = a[i];
            ++cot;
        }
        else if (lasb == nexts[i] && lasb != a[i]) {
            lasb = a[i];
            ++cot;
        }
        else if (lasa != a[i]) {
            lasa = a[i];
            ++cot;
        }
        else if (lasb != a[i]) {
            lasb = a[i];
            ++cot;
        }
    }

    cout << cot << "\n";

    return 0;
}