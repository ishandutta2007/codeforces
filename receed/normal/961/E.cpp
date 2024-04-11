#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 1 << 18;
int tr[N * 2];

void add(int v) {
    for (int i = N + v; i > 0; i /= 2)
        tr[i]++;
}

int sum(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[v];
    return sum(cl, cr, v * 2, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t, x = 0;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= i + 1)
            x++;
        e.push_back({min(a[i], n), i + 1});
    }
    sort(e.begin(), e.end());
    int cc = 0;
    for (auto v : e) {
        for (int i = cc; i < v.first; i++)
            add(min(a[i], n + 1));
        cc = v.first;
        ans += sum(v.second, n + 2);
    }
    cout << (ans - x) / 2;
}