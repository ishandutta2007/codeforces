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

const int N = (int)1e5 + 50;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vi p(n, 0);
        rep(i, 0, n) cin >> p[i], p[i]--;
        int s = 0;
        while(s < n && p[s] == s) s++;
        if(s < n) {
            int t;
            rep(i, 0, n) if(p[i] == s) t = i;
            reverse(p.begin() + s, p.begin() + t + 1);
        }
        rep(i, 0, n) cout << p[i] + 1 << " ";
        cout << '\n';
    }

}