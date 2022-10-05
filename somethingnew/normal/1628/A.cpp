#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
const int INF = 1e9 + 179;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }
    int ind = 0;
    vector<int> b;
    while (ind != n) {
        int t = 0;
        while (cnt[t] != 0)
            t++;
        vector<int> ad(t);
        int cg = t;
        if (a[ind] < t) {
            ad[a[ind]] = 1;
            cg--;
        }
        cnt[a[ind]]--;
        ind++;
        while (cg != 0) {
            if (a[ind] < t and ad[a[ind]] == 0) {
                ad[a[ind]] = 1;
                cg--;
            }
            cnt[a[ind]]--;
            ind++;
        }
        b.push_back(t);
    }
    cout << b.size() << '\n';
    for (auto i : b)
        cout << i << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) solve();
}