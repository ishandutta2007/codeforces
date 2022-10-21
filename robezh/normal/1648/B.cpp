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
const int N = (int)1e6 + 50;

int n, c, a[N];
int in[N], s[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> c;
        fill(s, s + c + 1, 0);
        fill(in, in + c + 1, 0);
        rep(i, 0, n) {
            cin >> a[i];
            in[a[i]] = 1;
        }
        rep(i, 1, c + 1) s[i] = s[i - 1] + in[i];
        bool bad = false;
        rep(i, 1, c + 1) {
            if(!in[i]) continue;
            for (int j = i; j <= c; j += i) {
                bad |= (s[min(c, j + i - 1)] - s[j - 1]) > 0 && !in[j / i];
            }
        }
        cout << (bad ? "No" : "Yes") << '\n';

    }




}