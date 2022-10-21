#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e6 + 50, mod = (int)1e9 + 13;
int p = 10003;

ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    s = " " + s;

    ll res = 0, L = 0, R = 0, P = 1;
    for(int i = 1; i <= s.length(); i++) {
        L = L * p + s[i]; L %= mod;
        R += P * s[i]; R %= mod;
        P *= p; P %= mod;
        if(L == R) {
            dp[i] = dp[i/2] + 1;
        }
        res += dp[i];
    }
    cout << res << endl;
}