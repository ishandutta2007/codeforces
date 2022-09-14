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

const int N = 10001;
ll cv[N], cnt[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cv[i] = cv[i - 1] + (i - 1) / 2;
    if (m > cv[n]) {
        cout << -1;
        return 0;
    }
    vector<ll> ans;
    ll mx = 1000000000;
    while (n > 0 && cv[n - 1] >= m) {
        ans.push_back(mx);
        mx -= n * 2 + 1;
        n--;
    }
    if (n > 0) {
        m -= cv[n - 1];
        ll cx = n;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < i; j++)
                cnt[i + j]++;
        while (cnt[cx] > m)
            cx++;
        ans.push_back(cx);
        for (n--; n; n--)
            ans.push_back(n);
    }
    reverse(all(ans));
    for (ll i : ans)
        cout << i << ' ';
}