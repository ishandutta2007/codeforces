#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e5 + 5;
ll to[50 * MAXN][2], cnt[MAXN], sz;
 
void add(ll x) {
     int cur = 0;
     for(ll b = 40; b >= 0; b--) {
            ll c = ((1LL << b) & x) >> b;
            if(to[cur][c] == -1)
                          to[cur][c] = ++sz;
            cur = to[cur][c];
     } 
}
 
ll maximize(ll x) {
    ll ans = 0;
    int cur = 0;
    for(ll b = 40; b >= 0; b--) {
        ll c = ((1LL << b) & x) >> b;
        if(to[cur][c^1] != -1) {
                    ans += (1LL << b);
                    cur = to[cur][c^1];
        }
        else
            cur = to[cur][c];
    }
    return ans;
}
 
int main() {
    for(int i = 0; i < 50*MAXN; i++)
            to[i][0] = to[i][1] = -1;
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    ll su = 0;
    add(su);
    for(int i = n - 1; i >= 0; i--) {
            su ^= v[i];
            add(su);        
    }
    ll ans = maximize(0), pf = 0;
    for(int i = 0; i < n; i++) {
            pf ^= v[i];
            ans = max(ans, maximize(pf));        
    }
    cout << ans << endl;
}