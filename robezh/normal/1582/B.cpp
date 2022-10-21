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
const int N = (int)66;

ll pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    rep(i, 1, 61) pw[i] = pw[i - 1] * 2;
    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        map<int, int> cnt;
        rep(i, 0, n) {
            int a; cin >> a;
            cnt[a]++;
        }
        cout << pw[cnt[0]] * cnt[1] << '\n';
    }


}