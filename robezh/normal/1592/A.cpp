#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e3 + 50;

int n;
int a[N], h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> h;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int x = a[n - 1], y = a[n - 2];
        int cnt = h / (x + y);
        h -= cnt * (x + y);
        int res = cnt * 2;
        if(h > 0) h -= x, res++;
        if(h > 0) h -= y, res++;
        cout << res << '\n';
    }


}