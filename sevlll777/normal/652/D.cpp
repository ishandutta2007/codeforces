// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int short
// #define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

vector<int> ftree1(2e6);//, ftree2(2e6);


void add(int pos, int diff, vector<int> &ftree) {
    for (int p = pos; p < 2e6; p = p | (p + 1)) {
        ftree[p] += diff;
    }
}

int sum(int pos, vector<int> &ftree) {
    int ans = 0;
    for (int p = pos; p >= 1; p = ((p & (p + 1)) - 1)) {
        ans += ftree[p];
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<tupint > seg;
    vector<int> crs;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        seg.pb({-l, r, i});
        crs.pb(r);
    }
    sort(seg.begin(), seg.end());
    sort(crs.begin(), crs.end());
    map<int, int> comp;
    for (int i = 0; i < n; i++) {
        comp[crs[i]] = i;
    }
    vector<int> ans(n);
    for (auto p : seg) {
        int r = get<1> (p), i = get<2> (p);
        ans[i] = sum(comp[r], ftree1);
        add(comp[r], 1, ftree1);
    }
    for (auto g : ans) {
        cout << g << ' ';
    }
}