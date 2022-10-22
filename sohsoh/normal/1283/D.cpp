/*
    Soheil Mohammadkhani
    hello friend :)
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
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m;
set<ll> st;
queue<ll> q, tmp_q, ans_q;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.insert(x);
        q.push(x);
    }

    ll d = 1;
    ll ans = 0;
    while (SZ(ans_q) < m) {
        ll x = q.front();
        if (st.find(x + 1) == st.end()) {
            st.insert(x + 1);
            ans += d;
            tmp_q.push(x + 1);
            ans_q.push(x + 1);
        }

        if (SZ(ans_q) == m) break;

        if (st.find(x - 1) == st.end()) {
            st.insert(x - 1);
            ans += d;
            tmp_q.push(x - 1);
            ans_q.push(x - 1);
        }

        q.pop();
        if (q.empty()) {
            while (!tmp_q.empty()) {
                q.push(tmp_q.front());
                tmp_q.pop();
            }

            d++;
        }
    }

    cout << ans << endl;
    while (!ans_q.empty()) {
        cout << ans_q.front() << sep;
        ans_q.pop();
    }

    cout << endl;
    return 0;
}