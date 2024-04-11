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
typedef pair<ll, int> pli;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int a[3];
        rep(i, 0, 3) cin >> a[i];
        sort(a, a + 3);
        bool good = false;
        good |= (a[0] + a[1] == a[2]);
        good |= (a[0] == a[1] && a[2] % 2 == 0);
        good |= (a[1] == a[2] && a[0] % 2 == 0);
        cout << (good ? "YES" : "NO") << '\n';
    }


}