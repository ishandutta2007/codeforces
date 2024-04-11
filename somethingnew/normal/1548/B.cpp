#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
struct que{
    vector<pair<int, int>> stc1, stc2;
    void push(int v) {
        if (stc1.empty()) {
            stc1.push_back({v, v});
        } else {
            stc1.push_back({v, __gcd(v, stc1.back().second)});
        }
    }
    void push2(int v) {
        if (stc2.empty()) {
            stc2.push_back({v, v});
        } else {
            stc2.push_back({v, __gcd(v, stc2.back().second)});
        }
    }
    void pop() {
        if (stc2.empty()) {
            while (!stc1.empty()) {
                push2(stc1.back().first);
                stc1.pop_back();
            }
        }
        stc2.pop_back();
    }
    int getgcd() {
        int gc = 0;
        if (!stc1.empty())
            gc = __gcd(gc, stc1.back().second);
        if (!stc2.empty())
            gc = __gcd(gc, stc2.back().second);
        return gc;
    }
    int getsz() {
        return stc1.size() + stc2.size();
    }
};
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    que q;
    for (auto & i : a)
        cin >> i;
    vector<int> b(n-1);
    for (int j = 0; j + 1 < n; ++j) {
        b[j] = abs(a[j + 1] - a[j]);
    }
    int res = 1;
    for (auto i : b) {
        q.push(i);
        while (q.getgcd() == 1) {
            q.pop();
        }
        res = max(res, q.getsz() + 1);
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}