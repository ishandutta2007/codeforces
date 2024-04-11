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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

bool f(int x, vector<int> &li) {
    vector<int> res(x, 1);
    rep(i, li.size() - x)
        if (li[i] != li[i + x])
            res[i % x] = 0;
    rep(i, x)
        if (res[i])
            return 1;
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> p(n), c(n), u(n);
        rep(i, n) {
            cin >> p[i];
            p[i]--;
        }
        rep(i, n)
            cin >> c[i];
        int ans = n;
        rep(i, n) {
            if (u[i])
                continue;
            int x = i;
            vector<int> li;
            while (!u[x]) {
                u[x] = 1;
                li.push_back(c[x]);
                x = p[x];
            }
            for (int j = 1; j * j <= li.size(); j++) {
                if (li.size() % j)
                    continue;
                if (f(j, li))
                    ans = min(ans, j);
                if (f(li.size() / j, li))
                    ans = min(ans, (int) li.size() / j);
            }
        }
        cout << ans << '\n';
    }

}