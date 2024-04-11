#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int dp[N];
int n;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> s >> t;
        s = " " + s;
        t = " " + t;
        int la0 = 0, la1 = 0;
        rep(i, 1, n + 1) {
            dp[i] = 0;
            if(s[i] == '0' || t[i] == '0') la0 = i;
            if(s[i] == '1' || t[i] == '1') la1 = i;
            if(la0 && la1) dp[i] = max(dp[i], dp[min(la0, la1) - 1] + 2);
            if(la1) {
                dp[i] = max(dp[i], dp[la1 - 1] + 0);
            }
            if(la0) {
                dp[i] = max(dp[i], dp[la0 - 1] + 1);
            }
        }
        cout << dp[n] << '\n';
    }


}