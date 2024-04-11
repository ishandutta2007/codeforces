#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
string s, t;
string rs;

bool solve() {

    cin >> s >> t;

    n = s.length(), m = t.length();
    for(int st1 = 0; st1 < n; st1++) {
        for(int len1 = 1; st1 + len1 <= n && len1 <=m; len1++) {
            int len2 = m - len1;
            int st2 = st1 + len1 - 1 - len2;
            if(st2 < 0) continue;
            string s2 = s.substr(st2, len2);
            reverse(all(s2));
            string s1 = s.substr(st1, len1);
            if(s1 + s2 == t) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "yes" : "no") << '\n';
    }


}