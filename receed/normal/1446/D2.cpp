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

const int N = 200001;
int a[N], c[N], mp[N * 2];
vector<int> li[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, mc = 0;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        c[a[i]]++;
        li[a[i]].push_back(i);
        if (c[a[i]] > c[mc])
            mc = a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i != mc && c[i] == c[mc])
            ans = n;
        if (c[i] < 200 || i == mc)
            continue;
        rep(j, n * 2 + 1)
            mp[j] = n;
        int cs = n;
        mp[cs] = -1;
        rep(j, n) {
            if (a[j] == mc)
                cs++;
            else if (a[j] == i)
                cs--;
            ans = max(ans, j - mp[cs]);
            if (mp[cs] == n)
                mp[cs] = j;
        }
    }
    li[mc].push_back(n);
    for (int i = 1; i <= n; i++) {
        if (c[i] >= 200 || !c[i] || i == mc)
            continue;
        ll cs = min(n, 2 * c[i] * (c[i] + 2));
        rep(j, cs * 2 + 1)
            mp[j] = n;
        mp[cs] = -1;
        int lp = 0;
        rep(jj, li[i].size()) {
            int j = li[i][jj];
            int pos = lower_bound(all(li[mc]), j) - li[mc].begin();
            lp = max(lp, pos - c[i] - 1);
            while (lp < li[mc].size() && li[mc][lp] < j) {
                cs++;
                if (mp[cs] == n)
                    mp[cs] = li[mc][lp];
                lp++;
            }
            ans = max(ans, j - 1 - mp[cs]);
            cs--;
            if (mp[cs] == n)
                mp[cs] = j;
            while (lp < li[mc].size() && (jj + 1 == li[i].size() || li[mc][lp] < li[i][jj + 1]) && lp < pos + c[i] + 1) {
                ans = max(ans, li[mc][lp] - 1 - mp[cs]);
                cs++;
                if (mp[cs] == n)
                    mp[cs] = li[mc][lp];
                lp++;
            }
        }
    }
    cout << ans;
}