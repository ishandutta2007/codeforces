#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353, N = 1005, M = N * N;
typedef pair<int, pair<int, int>> Pi;

int n,m,r,c;
int num[N][N];
ll ans[N][N];
ll inv[M];
Pi pi[M];

ll fp(ll x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k / 2);
    return k % 2 ? hf * hf % mod * x % mod : hf * hf % mod;
}

int main(){
    for(int i = 0; i < M; i++) inv[i] = fp(i, mod - 2);
    //cout << inv[5] * 5 % mod << endl;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &num[i][j]);
            int k = i * m + j;
            pi[k].first = num[i][j];
            pi[k].second.first = i, pi[k].second.second = j;
        }
    }
    scanf("%d%d", &r, &c);
    r--, c--;


    ll ans_sum = 0, sqrs = 0, sumx = 0, sumy = 0;
    sort(pi, pi + n * m);
    int ri = 0;
    for(int i = 0; i < n * m;){
        while(ri < n * m && pi[ri].first == pi[i].first) ri++;
        for(int j = i; j < ri; j++){
            int x = pi[j].second.first, y = pi[j].second.second;
            ll cans = ans_sum;
            cans = (cans + sqrs + 1LL * x * x % mod * i + 1LL * y * y % mod * i) % mod;
            cans -= (2 * sumx * x + 2 * sumy * y);
            cans = (cans % mod + mod) % mod;
            cans = (cans * inv[i]) % mod;
            ans[x][y] = cans;
            if(x == r && y == c) printf("%I64d\n", ans[x][y]);
        }

        for(int j = i; j < ri; j++){
            int x = pi[j].second.first, y = pi[j].second.second;
            ans_sum = (ans_sum + ans[x][y]) % mod;
            sqrs = (sqrs + 1LL * x * x + 1LL * y * y) % mod;
            sumx = (sumx + x) % mod;
            sumy = (sumy + y) % mod;
        }
        i = ri;
        //cout << ans_sum << " " << sqrs << " " << sumx << " " << sumy << endl;
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++) cout << ans[i][j] << " ";
//        cout << endl;
//    }


}