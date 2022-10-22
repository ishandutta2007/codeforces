/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 30;

ll n, q;
deque<ll> shift(deque<ll> q, ll n) {
    for (int i = 0; i < n; i++) {
        ll x = q.back();
        q.pop_back();
        q.push_front(x);
    }

    return q;
}

int main() {
    fast_io;
    cin >> n >> q;
    ll os = 0, es = 0;
    bool start = true;
    while (q--) {
        ll x;
        cin >> x;
        if (x == 1) {
            ll a;
            cin >> a;
            if (start) {
                os += floor(a / 2.0);
                es += ceil(a / 2.0);
            } else {
                os += ceil(a / 2.0);
                es += floor(a / 2.0);
            }

            if (abs(a) & 1) start = !start;
        } else start = !start;
    }

    os += n * MAXN * 2;
    es += n * MAXN * 2;
    os %= n;
    es %= n;

    deque<ll> oq, eq;
    for (int i = 1; i <= n; i++) {
        if (i & 1) oq.push_back(i);
        else eq.push_back(i);
    }

    oq = shift(oq, os);
    eq = shift(eq, es);

    for (int i = 0; i < n; i++) {
        if ((i & 1) ^ start) {
            cout << oq.front();
            oq.pop_front();
        } else {
            cout << eq.front();
            eq.pop_front();
        }

        cout << sep;
    }

    cout << endl;
    return 0;
}