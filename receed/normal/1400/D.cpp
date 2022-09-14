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

const int N = 3001;
ll a[N], pc[N][N], sc[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        rep(i, n) {
            cin >> a[i];
            a[i]--;
            rep(j, n)
                pc[j][i + 1] = pc[j][i];
            pc[a[i]][i + 1]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            rep(j, n)
                sc[j][i] = sc[j][i + 1];
            sc[a[i]][i]++;
        }
        ll ans = 0;
        rep(i, n)
            rep(j, i)
                ans += pc[a[i]][j] * sc[a[j]][i + 1];
        cout << ans << '\n';
        rep(i, n + 1)
            rep(j, n + 1)
                pc[i][j] = sc[i][j] = 0;
    }
}