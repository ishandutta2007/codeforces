// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
const long long LM = 1LL << 60;
using P = pair<long long, int>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> values(n, -1);
    vector<int> indices(n, -1);
    map<int, int> indices_set;
    vector<set<int>> sets(n);
    queue<int> empties;
    for (int i = 0; i < n; ++i) {
        empties.push(i);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        if (!indices_set.count(a[i])) {
            t = empties.front();
            empties.pop();
            values[t] = a[i];
            indices_set[values[t]] = t;
        }
        t = indices_set[a[i]];
        indices[i] = t;
        sets[t].insert(i);
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, w;
            cin >> i >> w;
            --i;
            int idx = indices[i];
            if (w == values[idx]) {
                continue;
            }
            if (indices_set.count(w)) {
                if (sets[idx].size() == 1) {
                    empties.push(idx);
                    sets[idx].clear();
                    indices_set.erase(values[idx]);

                    int new_idx = indices_set[w];
                    indices[i] = new_idx;
                    sets[new_idx].insert(i);
                }
                else {
                    assert(sets[idx].count(i));
                    sets[idx].erase(i);

                    int new_idx = indices_set[w];
                    indices[i] = new_idx;
                    sets[new_idx].insert(i);
                }
            }
            else {
                if (sets[idx].size() == 1) {
                    indices_set.erase(values[idx]);
                    values[idx] = w;
                    indices_set[values[idx]] = idx;
                }
                else {
                    assert(!empties.empty());
                    int new_idx = empties.front();
                    empties.pop();
                    indices_set[w] = new_idx;
                    indices[i] = new_idx;
                    values[new_idx] = w;
                    sets[idx].erase(i);
                    sets[new_idx].insert(i);
                }
            }
        }
        else if (t == 2) {
            int i;
            cin >> i;
            --i;
            cout << values[indices[i]] << '\n';
        }
        else {
            int L, R;
            cin >> L >> R;
            int m = (L + R) / 2;
            {
                // [l, m] -> l-1
                int l = L - 1;
                int r = m;
                int to = L - 1;
                auto itr = indices_set.lower_bound(l);
                if (itr != indices_set.end() && itr->first <= r) {
                    auto big_itr = itr;
                    ++itr;
                    while (itr != indices_set.end() && itr->first <= r) {
                        auto small_itr = itr;
                        if (sets[big_itr->second].size() < sets[small_itr->second].size()) {
                            swap(big_itr, small_itr);
                            assert(itr != small_itr);
                        }
                        for (auto& i : sets[small_itr->second]) {
                            indices[i] = big_itr->second;
                            sets[big_itr->second].insert(i);
                        }
                        sets[small_itr->second].clear();
                        empties.push(small_itr->second);
                        itr = indices_set.erase(small_itr);
                        if (itr == big_itr) ++itr;
                    }
                    int idx = big_itr->second;
                    values[idx] = to;
                    indices_set.erase(big_itr);
                    indices_set[to] = idx;
                }
            }
            {
                // [m+1, r] -> r + 1
                int l = m + 1;
                int r = R + 1;
                int to = R + 1;
                auto itr = indices_set.lower_bound(l);
                if (itr != indices_set.end() && itr->first <= r) {
                    auto big_itr = itr;
                    ++itr;
                    while (itr != indices_set.end() && itr->first <= r) {
                        auto small_itr = itr;
                        if (sets[big_itr->second].size() < sets[small_itr->second].size()) {
                            swap(big_itr, small_itr);
                            assert(itr != small_itr);
                        }
                        for (auto& i : sets[small_itr->second]) {
                            indices[i] = big_itr->second;
                            sets[big_itr->second].insert(i);
                        }
                        sets[small_itr->second].clear();
                        empties.push(small_itr->second);
                        itr = indices_set.erase(small_itr);
                        if (itr == big_itr) ++itr;
                    }
                    int idx = big_itr->second;
                    values[idx] = to;
                    indices_set.erase(big_itr);
                    indices_set[to] = idx;
                }
            }
        }
    }

    return 0;
}