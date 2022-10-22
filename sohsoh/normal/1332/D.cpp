/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                    cerr << #x << ": " <<  x <<  " ";

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int b_n(int n) {
    int res = 0;
    ll x = 1;
    while (n > 0 || x <= 131072) {
        if (n % 2 == 0) res += x;
        x *= 2;
        n /= 2;
    }

    return res;
}

int main() {
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); //cout << "__________________________________________" << endl;
    unsigned k;
    cin >> k;

    unsigned cok = b_n(k);
    //    cout << cok << endl;

    int mx = 262143;
    int a[2][3] = {0};
    a[0][0] = mx;
    a[0][1] = cok;
    a[0][2] = 0;
    a[1][0] = k;
    a[1][1] = mx;
    a[1][2] = k;

    cout << 2 << sep << 3 << endl;
    cout << a[0][0] << sep << a[0][1] << sep << a[0][2] << endl;
    cout << a[1][0] << sep << a[1][1] << sep << a[1][2] << endl;
    return 0;
}