#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pii, char> mp;
int n, q;
int ab = 0, aa = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, q) {
        char c;
        cin >> c;
        if(c == '+') {
            int u, v; char ch;
            cin >> u >> v >> ch;
            mp[{u, v}] = ch;
            if(mp.count({v, u})) {
                if(mp[{v, u}] == ch) aa++;
                ab++;
            }
        } else if(c == '-'){
            int u, v;
            cin >> u >> v;
            if(mp.count({v, u})) {
                if(mp[{v, u}] == mp[{u, v}]) aa--;
                ab--;
            }
            mp.erase({u, v});
        } else {
            int k;
            cin >> k;
            if(aa || (k % 2 == 1 && (ab))) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}