#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const ll SQ = 1e3 + 7;
const double EPS = 1e-8;
const ll MAXN = 1e6 + 7;

vector <ll> d(MAXN, 0);
vector <ll> p;

void init() {
    for (ll i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            p.push_back(i);
            d[i] = p.size() - 1;
        }
        for (ll j = 0; j <= d[i] && p[j] * i < MAXN; j++) {
            d[p[j] * i] = j;
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> cnt(MAXN, 0);
    cnt[0] = 1;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vector <ll> a, b;
        for (ll d = 1; d * d <= x; d++) {
            if (x % d) continue;
            a.push_back(d);
            if (d * d != x) {
                b.push_back(x / d);
            }
        }
        reverse(a.begin(), a.end());
        for (ll x : b) {
            cnt[x] += cnt[x - 1];
            if (cnt[x] >= INF) cnt[x] -= INF;
        }
        for (ll x : a) {
            cnt[x] += cnt[x - 1];
            if (cnt[x] >= INF) cnt[x] -= INF;
        }
    }
    ll res = 0;
    for (ll x = 1; x <= n; x++) {
        res += cnt[x];
        res %= INF;
    }
    cout << res;
}