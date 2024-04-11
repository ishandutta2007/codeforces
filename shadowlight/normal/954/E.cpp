#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const long double EPS = 1e-6;

long double calct(long double top, long double bot) {
    if (abs(bot) < EPS) {
        return 0;
    }
    return top / bot;
}

int sr(long double x, long double y) {
    if (abs(x - y) < EPS) {
        return 0;
    }
    if (x < y) {
        return -1;
    }
    return 1;
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
    ll n, T;
    cin >> n >> T;
    vector <pair <ll, ll> > a(n);
    long double top = 0, bot = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].second;
        bot += a[i].second;
    }
    long double res = 0;
    ll maxk = -1, mink = INF;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        top += a[i].first * a[i].second;
        maxk = max(maxk, a[i].first);
        mink = min(mink, a[i].first);
    }
    if (maxk < T || mink > T) {
        cout << 0;
        return 0;
    }
    if (calct(top, bot) > T) {
        sort(a.begin(), a.end());
    } else {
        sort(a.rbegin(), a.rend());
    }
    while (a.size() && sr(calct(top, bot), T) && sr(calct(top, bot), T) == sr(calct(top - a.back().first * a.back().second, bot - a.back().second), T)) {
        top -= a.back().first * a.back().second;
        bot -= a.back().second;
        a.pop_back();
    }
    cout << fixed << setprecision(10);
    assert(a.size());
    if (sr(calct(top, bot), T)) {
        long double a1 = a.back().first;
        long double b1 = a.back().second;
        long double x = (long double) (top - T * bot) / (a1 - T);
        assert(x < b1 + EPS);
        top -= x * a1;
        bot -= x;
        //cout << x << "\n";
        //cout << calct(top, bot) << "\n";
        assert(!sr(calct(top, bot), T));
    }
    cout << (long double) bot;
}