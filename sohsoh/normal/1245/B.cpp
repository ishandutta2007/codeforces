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

ll a, b, c, n, Ba, Bb, Bc, r_rem, p_rem, c_rem;

void print_something() {
    if (r_rem > 0) {
        cout << 'R';
        r_rem--;
        return;
    }

    if (p_rem > 0) {
        cout << 'P';
        p_rem--;
        return;
    }

    if (c_rem > 0) {
        cout << 'S';
        c_rem--;
        return;
    }
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> n >> a >> b >> c;
        Ba = Bb = Bc = 0;
        string s;
        cin >> s;
        for (char x : s) {
            if (x == 'R') Bb++;
            if (x == 'P') Bc++;
            if (x == 'S') Ba++;
        }

        ans += min(a, Ba);
        ans += min(b, Bb);
        ans += min(c, Bc);

        r_rem = a - Ba, p_rem = b - Bb, c_rem = c - Bc;

        if (ans < ceil(n / ld(2))) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (char x : s) {
                if (x == 'R') {
                    if (b > 0) {
                        b--;
                        cout << 'P';
                    } else print_something();
                }

                if (x == 'P') {
                    if (c > 0) {
                        c--;
                        cout << 'S';
                    } else print_something();
                }

                if (x == 'S') {
                    if (a > 0) {
                        a--;
                        cout << 'R';
                    } else print_something();
                }
            }

            cout << endl;
        }
    }
    return 0;
}