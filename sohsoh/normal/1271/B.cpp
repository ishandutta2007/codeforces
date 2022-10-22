/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[MAXN], b[MAXN], n;

deque<ll> solve(ll* c) {
    deque<ll> res;
    for (int i = 0; i < n - 1; i++) {
        if (c[i] == 1) {
            c[i] = 0;
            res.push_back(i);

            c[i + 1] = (c[i + 1] + 1) % 2;
        }
    }

    if (c[n - 1] == 1) res.push_front(INF);
    return res;
}

int main() {
    fast_io;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'B') {
            a[i] = 1;
            b[i] = 0;
        } else {
            a[i] = 0;
            b[i] = 1;
        }
    }


    deque<ll> res1 = solve(a), res2 = solve(b);
    ll s1 = res1.size(), s2 = res2.size();
    if (res1.front() == INF) s1 = INF;
    if (res2.front() == INF) s2 = INF;

    if (s1 == INF && s2 == INF) kill(-1);
    if (s1 < s2) {
        cout << s1 << endl;
        while (!res1.empty()) {
            cout << res1.front() + 1 << sep;
            res1.pop_front();
        }
    } else {
        cout << s2 << endl;
        while (!res2.empty()) {
            cout << res2.front() + 1 << sep;
            res2.pop_front();
        }
    }
    return 0;
}