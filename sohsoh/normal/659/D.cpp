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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll n;
    cin >> n;
    pll pp = {0, 0};
    ll pd = 0, ans = 0;
    cin >> pp.X;
    cin >> pp.Y;
    for (int i = 1; i <= n; i++) {
        pll p;
        cin >> p.X >> p.Y;
        ll xd = p.X - pp.X, yd = p.Y - pp.Y, d = 0;
        if (yd > 0) d = 0;
        else if (yd < 0) d = 2;
        else if (xd > 0) d = 1;
        else if (xd < 0) d = 3;

        if (pd == 1 && d == 0) ans++;
        if (pd == 0 && d == 3) ans++;
        if (pd == 3 && d == 2) ans++;
        if (pd == 2 && d == 1) ans++;

        pp = p;
        pd = d;
    }

    cout << ans << endl;
    return 0;
}