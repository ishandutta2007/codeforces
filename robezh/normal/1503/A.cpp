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

string t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cin >> t;
        string s, s2;
        int f = 0, c[2] = {0, 0};
        int cnt1 = 0;
        rep(i, 0, n) c[t[i] == '1']++;
        if(c[0] % 2 != 0 || t[0] == '0' || t[n - 1] == '0') {
            cout << "NO\n";
            continue;
        }
        rep(i, 0, n) {
            if(t[i] == '1') {
                if(cnt1 < c[1] / 2) {
                    s.push_back('(');
                    s2.push_back('(');
                    cnt1++;
                } else {
                    s.push_back(')');
                    s2.push_back(')');
                }
            } else {
                if(f == 0) {
                    s.push_back('(');
                    s2.push_back(')');
                } else {
                    s.push_back(')');
                    s2.push_back('(');
                }
                f ^= 1;
            }
        }
        cout << "YES\n";
        cout << s << endl;
        cout << s2 << endl;
    }
}