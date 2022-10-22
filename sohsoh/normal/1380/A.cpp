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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN];

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];
        ll a = -1, b, c;
        for (int i = 0; i < n; i++) {
            ll bi = -1, ai = -1;
            for (int j = 0; j < i; j++) if (A[j] < A[i]) bi = j;
            for (int j = i + 1; j < n; j++) if (A[j] < A[i]) ai = j;
            if (bi >= 0 && ai >= 0) {
                a = bi;
                b = i;
                c = ai;
            }
        }

        if (a >= 0) cout << "YES" << endl << a + 1 << sep << b + 1 << sep << c + 1 << endl;
        else cout << "NO" << endl;
    }
    return 0;
}