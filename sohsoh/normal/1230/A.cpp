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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll A[4];
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    ll s = A[0] + A[1] + A[2] + A[3];
    if (s & 1) return cout << "NO" << endl, 0;
    for (int i = 0; i < 4; i++) {
        if (A[i] == s / 2) return cout << "YES" << endl, 0;
        for (int j = i + 1; j < 4; j++) {
            if (A[i] + A[j] == s / 2) return cout << "YES" << endl, 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}