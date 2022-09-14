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


int a[10001];
vector<vector<int>> ans;

void op(int i, int j, int x) {
    if (!x)
        return;
    a[i] -= x * i;
    a[j] += x * i;
    ans.push_back({i, j, x});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, s;
    cin >> t;
    rep(z, t) {
        cin >> n;
        ans.clear();
        s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % n) {
            cout << "-1\n";
            continue;
        }
        s /= n;
        for (int i = 2; i <= n; i++) {
            op(1, i, (i - a[i] % i) % i);
            op(i, 1, a[i] / i);
        }
        for (int i = 2; i <= n; i++)
            op(1, i, s);
        cout << ans.size() << '\n';
        for (auto &pp : ans)
            cout << pp[0] << ' ' << pp[1] << ' ' << pp[2] << '\n';
    }
}