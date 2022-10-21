#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = (ll)1e9 + 7;
const int K = 10050, N = (int)1e5;
typedef pair<ll, int> P;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll n;
ll inv[N];
int k;
ll dp[20][55][K];
vector<P> dvs;

ll get(int k, int i, int j){
    if(dp[k][i][j] != -1) return dp[k][i][j];
    if(j == 0) return dp[k][i][j] = fp(dvs[k].first, i);
    dp[k][i][j] = 0;
    ll dvd = inv[i + 1];
    for(int t = 0; t <= i; t++){
        dp[k][i][j] += dvd * get(k, t, j-1) % mod;
    }
    dp[k][i][j] %= mod;
    return dp[k][i][j];
}

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    ll m = n;
    for(ll x = 2; x * x <= n; x++){
        if(m % x == 0){
            int cnt = 0;
            while(m % x == 0){
                m /= x;
                cnt++;
            }
            dvs.push_back({x, cnt});
        }
    }
    if(m > 1) dvs.push_back({m, 1});
    ll res = 1;
    for(int i = 0; i < dvs.size(); i++){
//        cout << dvs[i].first << " " << dvs[i].second << endl;
        res = (res * get(i, dvs[i].second, k)) % mod;
    }
    cout << res << endl;
}