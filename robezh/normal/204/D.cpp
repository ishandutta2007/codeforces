#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 5;
const ll mod = (int)1e9 + 7;


int n;
ll pw2[N];
ll pnon[N], snon[N], ssum[N];
int k;
string str;
string ch = "WBX";
int cnt[3][N];

ll count(int d, int i, int j) {
    return (cnt[d][j] - cnt[d][i-1]) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = pw2[i-1] * 2 % mod;

    cin >> n >> k;
    cin >> str;
    str = " " + str;
    for(int i = 1; i <= n; i++) {
        for(int d = 0; d < 3; d++) cnt[d][i] = cnt[d][i-1] + (str[i] == ch[d]);
    }
    pnon[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i < k) pnon[i] = pw2[cnt[2][i]];
        else {
            pnon[i] = pnon[i-1] * (str[i] == 'X' ? 2 : 1) % mod;
            if(count(0, i - k + 1, i) == 0) {
                pnon[i] -= (i - k == 0 ? 1 : (str[i-k] != 'B') * pnon[i-k-1]);
                pnon[i] %= mod;
            }
        }
    }
    snon[n+1] = 1;
    for(int i = n; i >= 1; i--) {
        if(n - i + 1 < k) snon[i] = pw2[count(2, i, n)];
        else {
            snon[i] = snon[i+1] * (str[i] == 'X' ? 2 : 1) % mod;
            if(count(1, i, i + k - 1) == 0) {
                snon[i] -= (i + k == n + 1 ? 1 : (str[i+k] != 'W') * snon[i+k+1]);
                snon[i] %= mod;
            }
        }
    }
    ssum[n+1] = 0;
    ll res = 0;
    for(int i = n; i >= 1; i--) {
        ssum[i] = ssum[i+1] * (str[i] == 'X' ? 2 : 1) % mod;
        if(n - i + 1 >= k && count(1, i, i + k - 1) == 0) {
            ssum[i] = (ssum[i] + (i + k == n + 1 ? 1 : (str[i+k] != 'W') * snon[i+k+1])) % mod;
        }
        if(i - 1 >= k && count(0, i - k, i - 1) == 0) {
            ll cur_p = (i - 1 == k ? 1 : (str[i-1-k] != 'B') * pnon[i-1-k-1]) % mod;
            res = (res + ssum[i] * cur_p) % mod;
        }
    }
    cout << (res % mod + mod) % mod;


}