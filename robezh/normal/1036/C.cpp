#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5][20];
int bit[20], b;
ll L,R;

ll get(int rem, int d, bool flag){
    if(rem < 0) return 0;
    if(d == -1) return rem >= 0;
    if(!flag && ~dp[rem][d]) return dp[rem][d];
    int lim = flag ? bit[d] : 9;
    ll res = 0;
    for(int i = 0; i <= lim; i++){
        res += get(i > 0 ? rem - 1 : rem, d - 1, flag && lim == i);
    }
    return flag ? res : dp[rem][d] = res;
}

ll solve(ll x){
    b = 0;
    ll t = x;
    while(t > 0){bit[b++] = int(t % 10); t /= 10;}
    return get(3, b-1, true);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    while(T--){
        cin >> L >> R;
        cout << solve(R) - solve(L-1) << endl;
    }
}