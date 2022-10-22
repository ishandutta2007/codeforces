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

const ll MAXN = 1e5 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct BIT {
    ll tree[MAXN] = {0};
    ll sum(ll ind) {
        ll ans = 0;
        ind++;

        while (ind > 0) {
            ans += tree[ind];
            ind -= ind & (-ind);
        }

        return ans;
    }

    void update(ll ind, ll diff) {
        ind++;
        while (ind <= MAXN) {
            tree[ind] += diff;
            ind += ind & (-ind);
        }
    }
};

BIT A[26];
ll q, S[MAXN];

int main() {
    fast_io;
    string s;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++) A[s[i] - 'a'].update(i, 1);
    for (int i = 0; i < s.size(); i++) S[i] = s[i] - 'a';
    while (q--) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll pos;
            char c;
            cin >> pos >> c;
            pos--; c -= 'a';
            A[S[pos]].update(pos, -1);
            A[c].update(pos, 1);
            S[pos] = c;
        } else {
            ll l, r;
            cin >> l >> r; l--; r--;
            ll ans = 0;
            for (int i = 0; i < 26; i++) {
                ll x = A[i].sum(r);
                if (l > 0) x -= A[i].sum(l - 1);
                if (x != 0) ans++;
            }

            cout << ans << endl;
        }
    }
    return 0;
}