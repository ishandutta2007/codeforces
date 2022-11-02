#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int n, l;
int a[N];

inline bool exists(int len) {
    set<int> vals;
    for (int i = 0; i < n; ++i) {
        if (vals.find(a[i] - len) != vals.end()) {
            return true;
        }
        vals.insert(a[i]);
    }
    return false;
}

inline set<int> get_points(int len) {
    set<int> res;
    for (int i = 0; i < n; ++i) {
        if (a[i] + len <= l) {
            res.insert(a[i] + len);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] - len >= 0) {
            res.insert(a[i] - len);
        }
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, y;
    scanf("%d %d %d %d", &n, &l, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    bool ex = exists(x), ey = exists(y);
    if (ex && ey) {
        cout << 0 << endl;
        return 0;
    }
    if (ex) {
        set<int> yp = get_points(y);
        cout << 1 << endl;
        cout << *yp.begin() << endl;
        return 0;
    }
    if (ey) {
        set<int> xp = get_points(x);
        cout << 1 << endl;
        cout << *xp.begin() << endl;
        return 0;
    }
    set<int> xp = get_points(x), yp = get_points(y);
    for (set<int>::iterator it = xp.begin(); it != xp.end(); ++it) {
        if (yp.find(*it) != yp.end()) {
            cout << 1 << endl;
            cout << *it << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    cout << *xp.begin() << " " << *yp.begin() << endl;
    return 0;
}