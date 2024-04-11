#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int c0, c1, c2;
        int a0, a1, a2, a3, a4;
        cin >> c0 >> c1 >> c2;
        cin >> a0 >> a1 >> a2 >> a3 >> a4;
        c0 -= a0;
        c1 -= a1;
        c2 -= a2;
        if(c0 < 0 || c1 < 0 || c2 < 0) {
            cout << "NO\n";
            continue;
        }
        cout << (c2 - (a3 - min(a3, c0)) - (a4 - min(a4, c1)) >= 0 ? "YES" : "NO") << '\n';
//        int t = min(a4, c0);/**/
//        a4
    }

}