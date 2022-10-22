#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

ll split(ll a, ll ck) {
    if (ck < 0) {
        return INFL;
    }
    ll par = ck + 1;
    ll smov = a / par;
    ll coub = a - smov * par;
    return (smov + 1) * (smov + 1) * coub + smov * smov * (par - coub);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    k -= n;
    vector<ll> a(n);
    ll sa = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sa += a[i];
    }
    ll ave = sa / (n + k) + 1;

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<int> ck(n, 0);
    for (int i = 0; i < n; ++i) {
        ck[i] = a[i] / ave;
        k -= ck[i];
    }

    for (int i = 0; i < n; ++i) {
        if (ck[i] < 0) {
            k += ck[i];
            ck[i] = 0;
        }
    }
    while (k > 0) {
        for (int i = 0; i < n; ++i) {
            ++ck[i];
            --k;
            if (k == 0) {
                break;
            }
        }
    }
    while (k < 0) {
        for (int i = 0; i < n; ++i) {
            int del = min<int>(0 - k, (ck[i] + 1) / 2);
            k += del;
            ck[i] -= del;
            if (k == 0) {
                break;
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        cout << ck[i] << " ";
    }*/

    priority_queue<pair<ll, pair<int, int>>> gain;
    priority_queue<pair<ll, pair<int, int>>> lose;
    for (int i = 0; i < n; ++i) {
        gain.push({ split(a[i], ck[i]) - split(a[i], ck[i] + 1), { i, ck[i] } });
        lose.push({ split(a[i], ck[i]) - split(a[i], ck[i] - 1), { i, ck[i] } });
    }

    while (gain.top().first + lose.top().first > 0) {
        int cg = gain.top().second.first;
        int cl = lose.top().second.first;
        ++ck[cg];
        --ck[cl];
        gain.push({ split(a[cg], ck[cg]) - split(a[cg], ck[cg] + 1), { cg, ck[cg] } });
        gain.push({ split(a[cl], ck[cl]) - split(a[cl], ck[cl] + 1), { cl, ck[cl] } });
        lose.push({ split(a[cg], ck[cg]) - split(a[cg], ck[cg] - 1), { cg, ck[cg] } });
        lose.push({ split(a[cl], ck[cl]) - split(a[cl], ck[cl] - 1), { cl, ck[cl] } });
        while (gain.top().second.second != ck[gain.top().second.first]) {
            gain.pop();
        }
        while (lose.top().second.second != ck[lose.top().second.first]) {
            lose.pop();
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += split(a[i], ck[i]);
        //cout << a[i] << ", " << ck[i] << ": " << split(a[i], ck[i]) << "\n";
    }

    cout << ans << "\n";

    return 0;
}