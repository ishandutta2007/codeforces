#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
int z[MAXN];

void zfunc(string s) {
    int l = -1, r = -1, n = s.length();
    memset(z, 0, sizeof z);
    for(int i = 1; i < n; i++) {
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int dp[MAXN];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    dp[1] = a;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + a;
        string t = s.substr(0, i);
        reverse(t.begin(), t.end());
        zfunc(t);
        int mx = 0;
        for(int j = i - 1; j > 0; j--) {
            mx = max(mx, z[j]);
            if(mx >= j)
                dp[i] = min(dp[i], dp[i - j] + b);
        }
    }
    cout << dp[n] << endl;
}