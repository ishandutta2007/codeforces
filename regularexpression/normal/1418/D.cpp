#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    set<int> have;
    for (int i = 0; i < n; ++i) {
        int pile;
        cin >> pile;
        have.insert(pile);
    }
    multiset<int> diff;
    for (auto it = have.begin(); next(it) != have.end(); it = next(it)) diff.insert(*next(it) - *it);
    auto print_ans = [&]() { if (have.size() <= 1) cout << "0\n"; else cout << *have.rbegin() - *have.begin() - *diff.rbegin() << '\n'; };
    print_ans();
    while (q--) {
        int type, pile;
        cin >> type >> pile;
        if (type == 0) {
            auto it = have.find(pile);
            bool ok_prev = it != have.begin(), ok_next = next(it) != have.end();
            if (ok_prev && ok_next) diff.insert(*next(it) - *prev(it));
            if (ok_prev) diff.erase(diff.find(*it - *prev(it)));
            if (ok_next) diff.erase(diff.find(*next(it) - *it));
            have.erase(it);
        } else {
            have.insert(pile);
            auto it = have.find(pile);
            bool ok_prev = it != have.begin(), ok_next = next(it) != have.end();
            if (ok_prev && ok_next) diff.erase(diff.find(*next(it) - *prev(it)));
            if (ok_prev) diff.insert(*it - *prev(it));
            if (ok_next) diff.insert(*next(it) - *it);
        }
        print_ans();
    }
    return 0;
}