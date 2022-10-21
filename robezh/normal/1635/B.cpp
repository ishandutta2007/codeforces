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

const int N = (int)2e5 + 50;

int n, a[N];

int is_local(int i) {
    return 0 <= i - 1 && i + 1 < n && a[i - 1] < a[i] && a[i] > a[i + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        int res = 0;
        rep(i, 0, n) {
            if(is_local(i)) {
                if(is_local(i + 2)) a[i + 1] = max(a[i], a[i + 2]);
                else a[i] = max(a[i - 1], a[i + 1]);
                res++;
            }
        }
        cout << res << '\n';
        rep(i, 0, n) cout << a[i] << " ";
        cout << '\n';
    }


}