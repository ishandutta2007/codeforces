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

const int N = 1000001, K = 1 << 20, M = 20;
int a[N], b[N], p1[N], p2[N], u1[K], u2[K], bc[K], cc[K], cl[K], per[M];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, m1 = 0, m2 = 0;
    string s1, s2;
    cin >> n >> m >> k >> s1 >> s2;
    rep(i, k) {
        m1 |= (s1[i] - '0') << i;
        m2 |= (s2[i] - '0') << i;
    }
    for (int i = 1; i < (1 << k); i++)
        bc[i] = bc[i & (i - 1)] + 1;
    p1[0] = m1;
    u1[0] = 1;
    p2[0] = m2;
    rep(i, k)
        per[i] = i;
    rep(i, n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if (((m1 >> per[a[i]]) & 1) != ((m1 >> per[b[i]]) & 1))
            m1 ^= (1 << per[a[i]]) ^ (1 << per[b[i]]);
        if (((m2 >> per[a[i]]) & 1) != ((m2 >> per[b[i]]) & 1))
            m2 ^= (1 << per[a[i]]) ^ (1 << per[b[i]]);
        swap(per[a[i]], per[b[i]]);
        if (!u1[m1]) {
            p1[i + 1] = m1;
            u1[m1] = 1;
        }
        else
            p1[i + 1] = -1;
        p2[i + 1] = m2;
    }
    for (int i = n; i >= 0; i--) {
        if (!u2[p2[i]])
            u2[p2[i]] = 1;
        else
            p2[i] = -1;
    }
    int k1 = k / 2, k2 = (k + 1) / 2, ans = k, l = 0, r = n, cm;
    rep(i, 1 << k)
        cc[i] = k + 1;
    for (int i = m; i <= n; i++) {
        if (p1[i - m] != -1)
            rep(j, 1 << k1) {
                cm = p1[i - m] ^ (j << k2);
                if (bc[j] < cc[cm]) {
                    cc[cm] = bc[j];
                    cl[cm] = i - m;
                }
            }
        if (p2[i] != -1)
            rep(j, 1 << k2) {
                cm = p2[i] ^ j;
                if (bc[j] + cc[cm] < ans) {
                    ans = bc[j] + cc[cm];
                    l = cl[cm];
                    r = i;
                }
            }
    }
    cout << k - ans << '\n' << l + 1 << ' ' << r;
}