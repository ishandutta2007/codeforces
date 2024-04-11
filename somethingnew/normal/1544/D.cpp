#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
//#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
pair<int, pair<vector<int>, vector<int>>> fans(int n,vector<int> zapr) {
    vector<int> seen(n);
    int aa = 0;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int x = zapr[i];
        if (x == -1)
            continue;
        if (seen[x] == 0) {
            bool ok = 1;
            if (aa == n - 2) {
                for (int j = 0; j < n; ++j) {
                    if (x != j and j != i) {
                        if (seen[j] == 0 and ans[j] == -1)
                            ok = 0;
                    }
                }
            }
            if (ok) {
                aa++;
                ans[i] = x;
                seen[x] = 1;
            }
        }
    }
    return {aa, {ans, seen}};
}
void solve() {
    int n;
    cin >> n;
    vector<int> q(n);
    for (auto &i : q) {
        cin >> i;i--;
    }
    auto [val1, ansseen1] = fans(n, q);
    vector<int> cnt(n);
    for (int i = n - 1; i >= 0; --i) {
        cnt[q[i]]++;
        if (cnt[q[i]] == 2){
            q[i] = -1;
            //cout << "FA";
            break;
        }
    }
    int val;
    auto [val2, ansseen2] = fans(n, q);
    vector<int> ans, seen;
    val = max(val1, val2);
    if (val1 > val2){
        ans = ansseen1.first;
        seen = ansseen1.second;
    } else {
        ans = ansseen2.first;
        seen = ansseen2.second;
    }
    deque<int> nums, target;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1 and seen[i] == 0) {
            nums.push_front(i);
            target.push_front(i);
        } else {
            if (ans[i] == -1)
                nums.push_back(i);
            if (seen[i] == 0)
                target.push_back(i);
        }
    }
    //for (auto i : ans)
    //    cout << i << ' ';
    //cout << endl;
    cout << val << '\n';
    for (int i = 0; i < nums.size(); ++i) {
        ans[nums[i]] = target[(i + 1) % nums.size()];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
        solve();
}