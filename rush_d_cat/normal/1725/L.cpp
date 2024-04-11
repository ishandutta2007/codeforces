#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct Bit {
    vector<LL> num;
    Bit(int n) { num.resize(n, 0); }
    void add(int pos) {
        for (size_t i = pos; i <= num.size(); i += i & -i) {
            ++num[i - 1];
        }
    }
    LL ask(int pos) {
        LL ans = 0;
        for (size_t i = pos; i; i -= i & -i) {
            ans += num[i - 1];
        }
        return ans;
    }
};

int main() {
    int n;
    vector<LL> vec, _;
    cin >> n;
    vec.resize(n);
    _.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        _[i] = vec[i];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] += vec[i - 1];
        _[i] += _[i - 1];
    }

    sort(_.begin(), _.end());
    _.erase(unique(_.begin(), _.end()), _.end());

    if (_[0] < 0 || vec.back() != _.back()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        vec[i] = lower_bound(_.begin(), _.end(), vec[i]) - _.begin() + 1;
    }

    Bit bit(_.size());
    LL ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += i - bit.ask(vec[i]);
        bit.add(vec[i]);
    }
    cout << ans << endl;
    return 0;
}