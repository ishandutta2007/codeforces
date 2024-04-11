#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[50][252][20];
int id[2600], cnt = 0;
int bit[20], b;

ll get(int lcm, int rem, int d, bool flag){
    if(d == -1) return rem % lcm == 0;
    if(!flag && ~dp[id[lcm]][rem][d]) return dp[id[lcm]][rem][d];
    ll res = 0; int upp = flag ? bit[d] : 9;
    for(int i = 0; i <= upp; i++){
        res += get((i == 0 ? lcm : lcm * i / __gcd(lcm, i)), d ? (rem * 10 + i) % 252 : (rem * 10 + i), d - 1, flag && i == bit[d]);
    }
    if(!flag) dp[id[lcm]][rem][d] = res;
    return res;
}

ll solve(ll x){
    ll t = x; b = 0;
    while(t > 0){bit[b++] = (int)(t % 10); t /= 10;}
    return get(1, 0, b-1, 1);
}

int main(){
    for(int i = 1; i <= 2520; i++){
        if(2520 % i == 0) id[i] = cnt++;
    }
    memset(dp, -1, sizeof(dp));

    int T;
    ll l, r;
    cin >> T;
    while(T--){
        cin >> l >> r;
        cout << solve(r) - solve(l-1) << endl;
    }
}