#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

map <ll, ll> val;
map <ll, bool> exist;

vector <ll> del;

ll f(ll x) {
    if (exist[x]) {
        return val[x];
    }
    ll res = power(2, x - 1);
    for (ll a : del) {
        if (a >= x) break;
        if (x % a == 0) {
            res = (res - f(a) + INF) % INF;
        }
    }
    exist[x] = 1;
    val[x] = res;
    return res;
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
    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0;
        return 0;
    }
    y /= x;
    for (ll i = 1; i * i < y; i++) {
        if (y % i == 0) {
            del.push_back(i);
            del.push_back(y / i);
        }
    }
    ll k = sqrt(y);
    if (k * k == y) {
        del.push_back(k);
    }
    sort(del.begin(), del.end());
//    for (ll a : del) {
//        cout << a << " " << f(a) << "\n";
//    }
    cout << f(y);
}