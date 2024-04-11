/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, char> pic;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i].X << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll find_res(ll a, ll b, ll c) {
    if (a == -1 || b == -1 || c == -1) return -1;
    return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}

ll minn(ll a, ll b) {
    if (a == -1) return b;
    if (b == -1) return a;

    return min(a, b);
}

int solve() {
    ll aa, bb, cc;
    cin >> aa >> bb >> cc;
    ll n = aa + bb + cc;

    vector<int> av;
    vector<int> bv;
    vector<int> cv;

    pair<ll, char>* a = new pair<ll, char>[n];
    int j = 0;
    for (int i = 0; i < aa; i++) {
        ll k;
        cin >> k;
        a[j] = make_pair(k, 'a');
        j++;

        av.push_back(k);
    }


    for (int i = 0; i < bb; i++) {
        ll k;
        cin >> k;
        a[j] = make_pair(k, 'b');
        j++;

        bv.push_back(k);
    }


    for (int i = 0; i < cc; i++) {
        ll k;
        cin >> k;
        a[j] = make_pair(k, 'c');
        j++;

        cv.push_back(k);
    }

    sort(a, a + n);
    Sort(av);
    Sort(bv);
    Sort(cv);


    av.push_back(av.back());
    bv.push_back(bv.back());
    cv.push_back(cv.back());
//    alog(a, n);
    ll la = -1;
    ll lb = -1;
    ll lc = -1;

    ll m = INF;

    for (int i = 0; i < n; i++) {
        if (a[i].Y == 'a') {
                la = a[i].X;
                av.erase(av.begin());
        }
        if (a[i].Y == 'b') {
                lb = a[i].X;
                bv.erase(bv.begin());
        }
        if (a[i].Y == 'c') {
                lc = a[i].X;
                cv.erase(cv.begin());
        }

        if (a[i].Y == 'a') {
            m = minn(find_res(a[i].X, lb, cv.front()), m);
            m = minn(find_res(a[i].X, bv.front(), lc), m);
            m = minn(find_res(a[i].X, lb, lc), m);
            m = minn(find_res(a[i].X, bv.front(), cv.front()), m);
        }

        if (a[i].Y == 'b') {
            m = minn(find_res(la, a[i].X, cv.front()), m);
            m = minn(find_res(av.front(), a[i].X, lc), m);
            m = minn(find_res(la, a[i].X, lc), m);
            m = minn(find_res(av.front(), a[i].X, cv.front()), m);
        }

        if (a[i].Y == 'c') {
            m = minn(find_res(av.front(), lb, a[i].X), m);
            m = minn(find_res(la, bv.front(), a[i].X), m);
            m = minn(find_res(la, lb, a[i].X), m);
            m = minn(find_res(av.front(), bv.front(), a[i].X), m);
        }
    }

    cout << m << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}