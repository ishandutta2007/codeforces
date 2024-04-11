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

const int N = 101;
int a[N], c[2], e[2];
vector<int> d[2];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    c[1] = (n + 1) / 2;
    c[0] = n / 2;
    rep(i, n) {
        cin >> a[i];
        if (a[i])
            c[a[i] % 2]--;
    }
    int l = -1, f = -1, cc, ans = 0, cnt = 0, fx;
    rep(i, n) {
        if (a[i] == 0) {
            cnt++;
            continue;
        }
        cc = a[i] % 2;
        if (l == -1) {
            fx = cnt;
            f = cc;
        }
        else if (l != cc)
            ans++;
        else
            d[cc].push_back(cnt);
        l = cc;
        cnt = 0;
    }
    if (l == -1) {
        cout << (n > 1 ? 1 : 0);
        return 0;
    }
    rep(z, 2) {
        ans += d[z].size() * 2;
        sort(all(d[z]));
        rep(i, d[z].size())
            if (d[z][i] <= c[z]) {
                ans -= 2;
                c[z] -= d[z][i];
            }
    }
    if (fx <= c[f])
        c[f] -= fx;
    else
        ans++;
    if (cnt <= c[l])
        c[l] -= cnt;
    else
        ans++;
    cout << ans;
}