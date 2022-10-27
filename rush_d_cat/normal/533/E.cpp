#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const LL MOD = 998244353;
const LL B = 131;
const LL B_ = 19790917;

char s[N], t[N];
int n, a[30], b[30];
LL sa[N], sb[N], pw[N];
LL gethash(int str, int pos, int x) {
    if (str == 0) {
        return (sa[pos] + pw[pos + 1] * x % MOD + B * (sa[n] - sa[pos] + MOD) % MOD) % MOD; 
    } else {
        return (sb[pos] + pw[pos + 1] * x % MOD + B * (sb[n] - sb[pos] + MOD) % MOD) % MOD;
    }
}
LL sa_[N], sb_[N], pw_[N];
int gethash_(int str, int pos, int x) {
    if (str == 0) {
        return sa_[pos] + pw_[pos + 1] * x + B_ * (sa_[n] - sa_[pos]);
    } else {
        return sb_[pos] + pw_[pos + 1] * x + B_ * (sb_[n] - sb_[pos]);
    }
}
int solve(int c1, int c2) {
    unordered_map<LL, int> m1, m2, m1_, m2_, g;
    c1 += 'a', c2 += 'a';
    for (int i = 0; i <= n; i ++) {
        if (t[i+1] != c1 && t[i] != c1);
        else {
            m1[gethash(0, i, c1)] ++;
            g[gethash(0, i, c1)] = gethash_(0, i, c1);
        }
        //if (i>=1 && t[i-1] != c1) continue;
        if (s[i+1] != c2 && s[i] != c2);
        else {
            m2[gethash(1, i, c2)] ++;
            m2_[gethash_(1, i, c2)] ++;
        }
    }
    int ans = 0;
    for (auto p: m1) {
        if (m2[p.first] && m2_[ g[p.first] ]) ans ++;
    }
    return ans;
}
 
int main() {
    pw[0] = 1; for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * B % MOD;
    pw_[0] = 1; for (int i = 1; i < N; i ++) pw_[i] = pw_[i-1] * B_;
 
    scanf("%d%s%s", &n, s+1, t+1);
    for (int i = 1; i <= n; i ++) {
        sa[i] = (sa[i - 1] + pw[i] * s[i] % MOD) % MOD;
        sb[i] = (sb[i - 1] + pw[i] * t[i] % MOD) % MOD;
        sa_[i] = sa_[i - 1] + pw_[i] * s[i];
        sb_[i] = sb_[i - 1] + pw_[i] * t[i];
    }
 
    for (int i = 1; i <= n; i ++) {
        a[ s[i] - 'a' ] ++;
        b[ t[i] - 'a' ] ++;
    }
    int ch1 = -1, ch2 = -1;
    for (int i = 0; i < 26; i ++) {
        if (a[i] < b[i]) ch1 = i;
        if (b[i] < a[i]) ch2 = i;
    }
 
    int ans = 0;
    if (ch1 == -1 && ch2 == -1) {
        for (int i = 0; i < 26; i ++) {
            ans = ans + solve(i, i);
        }
    } else {
        ans = ans + solve(ch1, ch2);
    }
    cout << ans << endl;
}