#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;
map<pair<int, int>, int> ansik;
void recsolve(set<pair<int, int>> a, int l, int r) {
    //cout << l << ' ' << r << endl;
    if (l > r)
        return;
    a.erase({l, r});
    vector<int> aboba(r-l+1, -1);
    for (auto [ll, rr] : a) {
        aboba[ll-l] = max(aboba[ll-l], rr-l);
    }
    int resind = 0;
    for (int i = 0; i < aboba.size(); ++i) {
        if (i + 1 < aboba.size())
            aboba[i + 1] = max(aboba[i + 1], aboba[i]);
        if (aboba[i] < i)
            resind = i;
    }
    resind += l;
    ansik[{l, r}] = resind + 1;
    set<pair<int, int>> left, right;
    for (auto i : a) {
        if (i.second < resind)
            left.insert(i);
        else
            right.insert(i);
    }
    recsolve(left, l, resind - 1);
    recsolve(right, resind + 1, r);
}
void solve() {
    set<pair<int, int>> segs;
    int n;
    ansik.clear();
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        a.push_back({l, r});
        segs.insert({l, r});
    }
    vector<int> zn(n, 1);
    recsolve(segs, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first + 1 << ' ' << a[i].second + 1 << ' ' << ansik[a[i]] << '\n';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}