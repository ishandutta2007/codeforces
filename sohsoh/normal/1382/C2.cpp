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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll B[MAXN], n, s = 0;

ll D(ll x) {
    return (x + s) % 2;
}

ll solve() {
    cin >> n;
    s = 0;
    deque<ll> A;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') A.push_back(1);
        else A.push_back(0);
    }


    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') B[i] = 1;
        else B[i] = 0;
    }

    vector<ll> ans;
    bool bc = true;
    for (int i = n - 1; i >= 0; i--) {
        if (bc) {
            if (D(A.back()) != B[i]) {
                if (D(A.front()) == B[i]) ans.push_back(1);
                ans.push_back(i + 1);
                A.pop_front();
                bc = !bc;
                s++;
            } else A.pop_back();
        } else {
            if (D(A.front()) != B[i]) {
                if (D(A.back()) == B[i]) ans.push_back(1);
                ans.push_back(i + 1);
                A.pop_back();
                bc = !bc;
                s++;
            } else A.pop_front();
        }
    }

    cout << ans.size() << sep;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}