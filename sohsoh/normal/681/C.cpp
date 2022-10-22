/*
    Soheil Mohammadkhani
    IDK :)
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
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9

int main() {
    fast_io;
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    queue<string> ans;

    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            ll k;
            cin >> k;
            q.push(k);
            ans.push(cmd + " " + to_string(k));
        } else if (cmd == "removeMin") {
            if (q.empty()) {
                ans.push("insert 1");
                q.push(1);
            }

            q.pop();
            ans.push("removeMin");
        } else if (cmd == "getMin") {
            ll k;
            cin >> k;
            while (!q.empty() && q.top() < k) {
                ans.push("removeMin");
                q.pop();
            }

            if (q.empty() || q.top() != k) {
                q.push(k);
                ans.push("insert " + to_string(k));
            }

            ans.push(cmd + " " + to_string(k));
        }
    }

    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
    return 0;
}