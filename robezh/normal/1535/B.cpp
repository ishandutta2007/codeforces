#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2005;
int n, a[N];

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
            rep(j, i + 1, n) {
                res += a[i] % 2 == 0 || a[j] % 2 == 0 || __gcd(a[i], a[j]) > 1;
            }
        }
        cout << res << '\n';
    }

}