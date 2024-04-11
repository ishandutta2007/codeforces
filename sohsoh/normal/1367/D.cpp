/*
    Soheil Mohammadkhani
    div 3 contest :)
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

const ll MAXN = 1e6 + 10; //Change this bullshit :| to prevent all of the runtimes :|
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, B[MAXN], C[MAXN];
string s;
char ans[MAXN];
bool filled[MAXN] = {false};

char find_the_best(ll x) {
    for (char c = 'z'; c >= 'a'; c--) {
        if (C[c] >= x) {
            C[c] = 0;
            return c;
        }

        C[c] = 0;
    }
    return 'X';
}

ll solve() {
    string s;
    cin >> s >> m;
    n = s.size();
    for (int i = 0; i < m; i++) cin >> B[i];
    fill(C + 'a', C + 'z' + 10, 0);
    fill(ans, ans + m + 10, 'N');
    for (char c : s) C[c]++;
    ll znum = count(B, B + m, 0);
    char zc = find_the_best(znum);
    for (int i = 0; i < m; i++) {
        if (B[i] == 0) {
            ans[i] = zc;
        }
    }

    vector<ll> v = {0};
    while (!v.empty()) {
        v.clear();
        for (int i = 0; i < m; i++) {
            if (ans[i] != 'N') continue;
            ll sum = 0;
            for (int j = 0; j < m; j++) {
                if (ans[j] == 'N') continue;
                sum += abs(j - i);
            }

            if (sum == B[i]) {
                v.push_back(i);
            }
        }

        char c = find_the_best(v.size());
        for (ll e : v) {
            ans[e] = c;
        }
    }

    for (int i = 0; i < m; i++) cout << ans[i];
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