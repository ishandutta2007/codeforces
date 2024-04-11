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

const int N = 1000004;
int ans[N];
vector<pair<int, int>> a;

void go(int l, int r, int i) {
    int f = 0, ca = 0;
    for (int j = l; j < r; j++) {
        f += a[j].first;
        ca += f / i;
        f %= i;
        if (f + a[j].second >= i) {
            ca++;
            f = a[j].second - (i - f);
        }
        else
            f = a[j].second;
    }
    if (!ca)
        return;
    ans[i] += ca;
    int li = l;
    for (int j = l; j < r; j++)
        if (a[j].first + a[j].second + (j == l ? 0 : a[j - 1].second) <= i && (j == r - 1 || a[j].second + a[j + 1].first + a[j + 1].second <= i)) {
            go(li, j, i + 1);
            li = j + 1;
        }
    go(li, r, i + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ls = -1, lc = 0, cq = 0, cs;
    for (char c : s) {
        if (c == '?')
            cq++;
        else {
            cs = c - '0';
            if (ls == cs || ls == -1)
                lc += cq + 1;
            else {
                a.push_back({lc, cq});
                lc = 1;
            }
            cq = 0;
            ls = cs;
        }
    }
    lc += cq;
    if (ls == -1)
        ls = 0;
    a.push_back({lc, 0});
    go(0, a.size(), 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}