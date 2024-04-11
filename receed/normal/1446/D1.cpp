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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, mc = 0;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        c[a[i]]++;
        if (c[a[i]] > c[mc])
            mc = a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (!c[i] || i == mc)
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
    cout << ans;
}