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

ll n, k, A[MAXN];

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);
    ll pref_len = 1, pref_ind = 0, pref = A[0];
    ll suff_len = 1, suff_ind = n - 1, suff = A[n - 1];
    while (pref < suff && suff_ind > 0 && pref_ind + 1 < n && k > 0) {
        if (suff_len < pref_len) {
            ll m = min(k / suff_len, suff - A[suff_ind - 1]);
            suff -= m;
            k -= m * suff_len;
            suff_ind--;
            suff_len++;
        } else {
            ll m = min(k / pref_len, A[pref_ind + 1] - pref);
            pref += m;
            k -= m * pref_len;
            pref_ind++;
            pref_len++;
        }
    }

    cout << suff - pref << endl;
    return 0;
}