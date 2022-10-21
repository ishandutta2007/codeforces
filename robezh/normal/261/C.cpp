#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int B = 60;

ll n, t;

ll dp[B][B];
int bit[B], b;

ll get(int rem, int d, bool flag){
    if(rem < 0) return 0;
    if(d == -1) return rem == 0;
    if(!flag && ~dp[rem][d]) return dp[rem][d];
    int lim = flag ? bit[d] : 1;
    ll res = 0;
    for(int i = 0; i <= lim; i++){
        res += get(rem - i, d - 1, flag && lim == i);
    }
    return flag ? res : dp[rem][d] = res;
}

ll solve(ll x, int cnt){
    memset(dp, -1, sizeof(dp));
    b = 0;
    ll t = x;
    while(t > 0){bit[b++] = (int)(t % 2); t /= 2;}
    return get(cnt, b-1, true);
}

int main() {
    cin >> n >> t;
    if(__builtin_popcountll(t) != 1) return cout << 0 << endl, 0;
    int cnt = 0;
    while(t > 0) {cnt++, t /= 2;}
    cout << solve(n + 1, cnt) - solve(1, cnt) << endl;
}