#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> mp;
    rep(i, 1, 105) mp[i * i] = 1;
    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        bool found = false;
        rep(i, 0, n) {
            int c; cin >> c;
            if(!mp[c]) found = true;
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
}