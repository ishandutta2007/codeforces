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
ll a[N], ans;

int go(int l, int r, int p) {
    if (r - l == 0 || p == -1)
        return 1;
    if ((a[l] & (1 << p)) || !(a[r] & (1 << p)))
        return go(l, r, p - 1);
    int m1 = l, m2 = r;
    while (!(a[m1] & (1 << p)) && (a[m2] & (1 << p))) {
        m1++;
        m2--;
    }
    if (!(a[m1] & (1 << p)))
        m1 = m2 + 1;
   return max(go(l, m1 - 1, p - 1), go(m1, r, p - 1)) + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i, n)
        cin >> a[i];
    sort(a, a + n);
    cout << n - go(0, n - 1, 30);
}