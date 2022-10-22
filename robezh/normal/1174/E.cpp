#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50, mod = (int)1e9 + 7, LOG = 22;

int n;
ll dp[2][LOG][2];
int pw2[N];

void add(ll &to, ll x) {
    to += x;
    if(to >= mod) to -= mod;
}

int count(int divi) {
    return n / divi;
}

int main() {
    cin >> n;
    pw2[0] = 1;
    for(int i = 1; i < LOG; i++) pw2[i] = pw2[i-1] * 2;
    int mx = 0;
    for(int i = 1; i < LOG; i++) if(pw2[i] <= n) mx = i;
    int nw = 0, la = 1;
    dp[nw][mx][0] = 1;
    if(pw2[mx-1] * 3 <= n) dp[nw][mx-1][1] = 1;
    for(int i = 2; i <= n; i++) {
        swap(la, nw);
        memset(dp[nw], 0, sizeof(dp[nw]));
        for(int j = 0; j <= mx; j++) {
            add(dp[nw][j][0], dp[la][j][0] * max(0, count(pw2[j]) - (i - 1)) % mod);
            add(dp[nw][j][0], dp[la][j + 1][0] * (count(pw2[j]) - count(pw2[j + 1])) % mod);
            add(dp[nw][j][0], dp[la][j][1] * (count(pw2[j]) - count(pw2[j] * 3)) % mod);
            add(dp[nw][j][1], dp[la][j+1][1] * (count(pw2[j] * 3) - count(pw2[j+1] * 3)) % mod);
            add(dp[nw][j][1], dp[la][j][1] * (count(pw2[j] * 3) - (i - 1)) % mod);
        }
    }
    cout << dp[nw][0][0] << endl;

}