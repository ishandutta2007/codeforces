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

const ll MAXN = 1e6 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, A[MAXN], B[MAXN];

bool can1(ll x) {
    if (A[0] > x) return false;
    ll t = k - 2;
    ll i = 2;
    while (t > 0 && i < n) {
        if (A[i] <= x) {
            t--;
            if (i + 1 < n) {
                t--;
                i++;
            }
        }

        i++;
    }

    if (t > 0) return false;
    return true;
}

bool can2(ll x) {
    ll t = k - 1;
    ll i = 1;
    while (t > 0 && i < n) {
        if (A[i] <= x) {
            t--;
            if (i + 1 < n) {
                t--;
                i++;
            }
        }

        i++;
    }

    if (t > 0) return false;
    return true;
}

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> A[i], B[i] = A[i];
    sort(B, B + n);
    ll L = 0, R = n - 1;
    while (L < R) {
        ll mid = (L + R) / 2;
        ll mid_ans = B[mid];
        if (can1(mid_ans) || can2(mid_ans)) R = mid;
        else L = mid + 1;
    }

    cout << B[L] << endl;
    return 0;
}