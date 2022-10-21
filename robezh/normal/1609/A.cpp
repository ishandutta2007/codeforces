#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> P;
const int N = (int)16;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        ll sum = 0, mx = 0, pw = 1;
        rep(i, 0, n) {
            cin >> a[i];
            while(a[i] % 2 == 0) {
                a[i] /= 2;
                pw *= 2;
            }
            sum += a[i];
            mx = max(mx, a[i]);
        }
        cout << sum + mx * (pw - 1) << '\n';
    }

}