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

ll A[MAXN], B[MAXN], n;

ll solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') A[i] = 1;
        else A[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') B[i] = 1;
        else B[i] = 0;
    }

    vector<ll> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            if (A[0] == B[i]) ans.push_back(1), A[0] = (A[0] + 1) % 2;
            ans.push_back(i + 1);
            for (int j = 0; j <= i; j++) A[j] = (A[j] + 1) % 2;
            reverse(A, A + i + 1);
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