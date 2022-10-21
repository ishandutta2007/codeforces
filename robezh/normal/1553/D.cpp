#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s, t;

bool solve() {
    cin >> s >> t;
    if(s.length() % 2 != t.length() % 2) s = s.substr(1);
    int cur = 0;
    rep(i, 0, sz(t)) {
        while(cur < sz(s) && s[cur] != t[i]) cur += 2;
        if(cur >= sz(s)) return false;
        cur++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << '\n';

    }

}