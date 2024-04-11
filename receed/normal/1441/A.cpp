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

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    cin >> t;
    rep(z, t) {
        cin >> n >> k;
        vector<int> a(n), b(k), pos(n), f(n);
        rep(i, n) {
            cin >> a[i];
            pos[a[i] - 1] = i;
        }
        rep(i, k) {
            cin >> b[i];
            b[i] = pos[b[i] - 1];
            f[b[i]] = 1;
        }
        set<int> s;
        rep(i, n)
            s.insert(i);
        ll ans = 1;
        for (int i : b) {
            auto it = s.find(i);
            int pr = (it == s.begin() ? -1 : *prev(it));
            int nx = (it == prev(s.end()) ? -1 : *next(it));
            if (pr != -1 && f[pr])
                pr = -1;
            if (nx != -1 && f[nx])
                nx = -1;
            if (pr == -1 && nx == -1) {
                ans = 0;
                break;
            }
            f[i] = 0;
            if (pr == -1) {
                s.erase(nx);
            }
            else {
                s.erase(pr);
                if (nx != -1)
                    ans = ans * 2 % MOD;
            }
        }
        cout << ans <<'\n';
    }
}