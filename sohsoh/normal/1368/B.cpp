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

const ll MAXN = 1e6 + 10; //change this
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string cf = "codeforces";

int main() {
    fast_io;
    ll ans = 0;
    ll k;
    cin >> k;
    int i;
    for (i = 1; ans < k; i++) {
        ans = 1;
        for (int j = 0; j < 10; j++) {
            ans *= i;
        }
    }

    i--;
    i--;
    int x = 0;
    ans = 0;
    for (x = 0; x <= 10 && ans <= k; x++) {
        ans = 1;
        for (int j = 0; j < x; j++) {
            ans *= (i + 1);
        }

        for (int j = x; j < 10; j++) {
            ans *= (i);
        }

        if (ans >= k) {
            for (int j = 0; j < x; j++) {
                for (int m = 0; m < i + 1; m++) cout << cf[j];
            }


            for (int j = x; j < 10; j++) {
                for (int m = 0; m < i; m++) cout << cf[j];
            }

            cout << endl;
            return 0;
        }
    }
    return 0;
}