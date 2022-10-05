#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"

typedef double ld;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
using namespace std;
int corr(vector<int> a, int perm) {
    int n = a.size();
    vector<int> ps(n);
    for (int i = 0; i < n; ++i) {
        ps[a[i]] = i;
    }
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != (perm + i) % n) {
            ps[a[i]] = ps[(perm + i) % n];
            swap(a[i], a[ps[(perm + i) % n]]);
            m++;
        }
    }
    return m;
}
void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> perms(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        perms[(n + a[i] - i) % n]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (perms[i] >= n / 4 and corr(a, i) <= m)
            ans.push_back((n-i)%n);
    }
    sort(all(ans));
    cout << ans.size() << ' ';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}