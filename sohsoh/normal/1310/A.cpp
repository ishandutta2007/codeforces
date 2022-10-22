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

//Y: type

ll cost = 0, n, ans = 0;
priority_queue<ll> q;
pll a[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].X;
    for (int i = 0; i < n; i++) cin >> a[i].Y;
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        ll diff = 0;
        if (i > 0) diff = a[i].X - a[i - 1].X;

        ll d = 0;
        while (diff && !q.empty()) {
            cost -= q.top();
            ans += cost;
            q.pop();
            diff--;
        }

        q.push(a[i].Y);
        cost += a[i].Y;

    }

    while (!q.empty()) {
        cost -= q.top();
        ans += cost;
        q.pop();
    }

    cout << ans << endl;
    return 0;
}