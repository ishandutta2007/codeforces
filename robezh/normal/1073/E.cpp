#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

pair<ll, ll> dp[1500][20][2];
bool vis[1500][20][2];
int bit[20], b;
ll cnt[1500];
ll pw10[20];
ll A, B, k;

pair<ll, ll> get(int sta, int d, bool st, bool flag){
    if(cnt[sta] > k) return {0, 0};
    if(d == -1) return {1, 0};
    if(!flag && vis[sta][d][st]) return dp[sta][d][st];
    vis[sta][d][st] = true;
    ll res0 = 0, res1 = 0;
    int lim = flag ? bit[d] : 9;
    for(int i = 0; i <= lim; i++){
        auto p = get((st || (i != 0) ? (sta | (1 << i)) : 0), d - 1, st || (i != 0), flag && lim == i);
        res0 = (res0 + p.first) % mod;
        res1 = (res1 + i * pw10[d] % mod * p.first % mod + p.second) % mod;
    }
    if(!flag) dp[sta][d][st].first = res0, dp[sta][d][st].second = res1;
    return {res0, res1};
}

ll solve(ll x){
    memset(vis, 0, sizeof(vis));
    b = 0;
    ll t = x;
    while(t > 0){bit[b++] = (int)(t % 10); t /= 10;}
    return get(0, b-1, false, true).second;
}

int main(){
    for(int i = 0; i < 1024; i++){
        cnt[i] = 0;
        for(int j = 0; j < 10; j++) cnt[i] += ((i >> j) & 1);
    }
    pw10[0] = 1;
    for(int i = 1; i < 20; i++) pw10[i] = pw10[i-1] * 10 % mod;
    cin >> A >> B >> k;
    cout << (solve(B) - solve(A - 1) + mod) % mod << endl;
}