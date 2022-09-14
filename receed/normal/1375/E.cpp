#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1001;
int p[N];
int n;
vector<pair<int, int>> ans;

void go(int i) {
    ans.push_back({p[i + 1], p[i]});
    swap(p[i], p[i + 1]);
    if (i > 0 && p[i - 1] > p[i])
        go(i - 1);
    if (i + 1 < n - 1 && p[i + 1] > p[i + 2])
        go(i + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    rep(i, n)
        p[i] = a[i].second;
    rep(i, n - 1)
        if (p[i] > p[i + 1])
            go(i);
    cout << ans.size() << '\n';
    for (auto &pp : ans)
        cout << pp.first + 1 << ' ' << pp.second + 1 << '\n';
}