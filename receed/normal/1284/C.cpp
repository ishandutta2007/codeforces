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

const int N = 250002;
ll f[N];
ll n, m;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % m;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + (n - i + 1) * (n - i + 1) % m * f[i] % m * f[n - i] % m) % m;
    cout << ans;
}