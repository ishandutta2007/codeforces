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
const int N = (int)2e5 + 50;

int n;
vi dvs[N];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) dvs[j].push_back(i);
    }
    int T;
    cin >> T;
    while(T--) {
        int g = 0;
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(b, 0, 30) {
            int cnt = 0;
            rep(j, 0, n) cnt += (a[j] >> b & 1);
            g = __gcd(cnt, g);
        }
        if(g == 0) {
//            cout << n << '\n';
            rep(i, 1, n + 1) cout << i << " ";
            cout << '\n';
        } else {
//            cout << dvs[g].size() << '\n';
            for (int x : dvs[g]) cout << x << " ";
            cout << '\n';
        }
    }

}