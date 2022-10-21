#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005, mod = (int)1e9 + 7;

int tn;
int m, magic;
ll dp[N][N];
int pw10[N];
int bit[N], b;
int n;
string str1, str2;

ll get(int rem, int d, bool flag){
    if(d == -1) return rem == 0;
    if(!flag && ~dp[rem][d]) return dp[rem][d];
    int lim = flag ? bit[d] : 9;
    ll res = 0;
    if((tn - d) % 2 == 0) {
        if(magic <= lim) res = get((rem + pw10[d] * magic) % m, d - 1, flag && lim == magic);
    }
    else {
        for(int i = 0; i <= lim; i++){
            if(i == magic) continue;
            res += get((rem + pw10[d] * i) % m, d - 1, flag && lim == i);
        }
    }

    res %= mod;
    return flag ? res : dp[rem][d] = res;
}

ll solve(string &s){
    memset(dp, -1, sizeof(dp));
    n = s.length();
    for(int i = 0; i < n; i++) {
        bit[i] = s[n-1-i] - '0';
    }
    for(int i = n; i < tn; i++) bit[i] = 0;
    return get(0, tn-1, true);
}

void decre(string &s) {
    int len = s.length();
    for(int i = len - 1; i >= 0; i--) {
        s[i] --;
        if(s[i] - '0' >= 0) break;
        s[i] += 10;
    }
    if(s[0] == '9' && len == 1) {
        s = "-1";
    }
    else if(s[0] == '0' && len > 1) s = s.substr(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> magic;
    pw10[0] = 1;
    for(int i = 1; i < N; i++) pw10[i] = pw10[i-1] * 10 % m;

    cin >> str1 >> str2;
    tn = str1.length();
    decre(str1);

    ll res = solve(str2);
    if(str1 != "-1") res = (res - solve(str1) + mod) % mod;
    cout << res << endl;

}