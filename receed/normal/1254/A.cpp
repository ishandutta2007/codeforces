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

const int N = 102;
char a[N][N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, m, k;
    vector<char> li;
    rep(i, 10)
        li.push_back('0' + i);
    rep(i, 26) {
        li.push_back('a' + i);
        li.push_back('A' + i);
    }
    cin >> t;
    rep(z, t) {
        cin >> n >> m >> k;
        int cc = 0;
        rep(i, n) {
            cin >> a[i];
            rep(j, m)
                if (a[i][j] == 'R')
                    cc++;
        }
        int lc = 0, ck = 0;
        vector<string> ans(n, string(m, ' '));
        int d = cc % k;
        rep(i, n) {
            if (i % 2 == 0)
                rep(j, m) {
                    ans[i][j] = li[ck];
                    if (a[i][j] == 'R')
                        lc++;
                    if (ck != k - 1 && ((ck < d && lc == cc / k + 1) || (ck >= d && lc == cc / k))) {
                        lc = 0;
                        ck++;
                    }
                }
            else
                for (int j = m - 1; j >= 0; j--) {
                    ans[i][j] = li[ck];
                    if (a[i][j] == 'R')
                        lc++;
                    if (ck != k - 1 && ((ck < d && lc == cc / k + 1) || (ck >= d && lc == cc / k))) {
                        lc = 0;
                        ck++;
                    }
                }
        }
        rep(i, n)
            cout << ans[i] << '\n';
    }
}