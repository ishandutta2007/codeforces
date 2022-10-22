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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, A[MAXN];
bool ok[MAXN] = {false};
pll B[MAXN];
vector<ll> v[MAXN];
queue<ll> q;
stack<ll> ans;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(i);
        v[y].push_back(i);
        A[x]--;
        A[y]--;
        B[i] = {x, y};
    }

    for (int i = 1; i <= n; i++) if (A[i] >= 0) q.push(i);
    while (!q.empty() && ans.size() < m) {
        ll f = q.front();
        q.pop();
        A[f] = -INF;
        for (ll p : v[f]) {
            if (ok[p]) continue;
            ll o = B[p].X;
            if (o == f) o = B[p].Y;
            ok[p] = true;
            ans.push(p);
            A[o]++;
            if (A[o] >= 0) q.push(o);
        }
    }

    if (ans.size() < m) return cout << "DEAD" << endl, 0;
    cout << "ALIVE" << endl;
    while (!ans.empty()) {
        cout << ans.top() + 1 << sep;
        ans.pop();
    }

    cout << endl;
    return 0;
}