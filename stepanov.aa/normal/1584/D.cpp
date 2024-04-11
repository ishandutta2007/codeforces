#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <array>
#include <random>
#include <ctime>
#include <deque>
#include <set>
#include <map>


using namespace std;


#define int long long
#define ll long long
#define ld long double
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back


ll n;


ll ask(ll l, ll r) {
    cout << "? " << l + 1 << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}


void ans(ll i, ll j, ll k) {
    cout << "! " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
}


ll get_x(ll inv) {
    inv *= 2;
    ll l = 0;
    ll r = 1e9;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (m * (m - 1) <= inv) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l * (l - 1) == inv) {
        return l;
    }
    return -1;
}


ll get_ln1(ll ln, ll x) {
    x *= 2;
    ll l = 0;
    ll r = ln / 2 + 1;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll a = m;
        ll b = ln - m;
        if (a * (a - 1) + b * (b - 1) >= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}


int32_t main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll l = -1;
        ll r = n;
        ll x = ask(0, n);
        ll bg = -1;
        ll nd = -1;
        while (true) {
            ll m = (l + r) / 2;
            ll a = ask(0, m + 1);
            if (a == 0) {
                l = m;
            } else if (a == x) {
                r = m;
            } else {
                ll ln = get_x(a);
                if (ln == -1) {
                    ll a2 = ask(m + 1, n);
                    ll ln2 = get_x(a2);
                    nd = m + ln2;
                } else {
                    ll k = m + 1 - ln;
                    ll a2 = ask(0, k + 1);
                    if (a2 == 0) {
                        bg = k;
                    } else {
                        ll a3 = ask(m + 1, n);
                        ll ln2 = get_x(a3);
                        nd = m + ln2;
                    }
                }
                break;
            }
        }
        if (bg != -1) {
            l = bg;
            while (l + 1 < r) {
                ll m = (l + r) / 2;
                ll a = ask(0, m + 1);
                if (a < x) {
                    l = m;
                } else {
                    r = m;
                }
            }
            nd = r;
        } else {
            r = nd;
            while (l + 1 < r) {
                ll m = (l + r) / 2;
                ll a = ask(0, m + 1);
                if (a == 0) {
                    l = m;
                } else {
                    r = m;
                }
            }
            bg = l;
        }
        ll ln = nd - bg + 1;
        ll a = get_ln1(ln, x);
        ll j1 = bg + a;
        ll j2 = nd - a + 1;
        if (ask(bg, j1) + ask(j1, nd + 1) == x) {
            ans(bg, j1, nd);
        } else {
            ans(bg, j2, nd);
        }
    }
    return 0;
}