#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = (int)1e5 + 50, N = (int)1e6 + 50;
const ll INF = (ll)2e18;

bool p[M];
int mu[M], pm[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int n, a, b;
set<int> ps;
int num[N];
ll psum[N], pcomb[N];
ll ssum[N];
ll cost[N];

void put_list(int x) {
    for(int i = 0; i < pms; i++) {
        if(x % pm[i] == 0) {
            ps.insert(pm[i]);
            while(x % pm[i] == 0) x /= pm[i];
        }
    }
    if(x > 1) ps.insert(x);
}

ll solve(int g) {
    for(int i = 0; i < n; i++) {
        if(num[i] % g == 0) cost[i] = 0;
        else if((num[i] - 1) % g == 0 || (num[i] + 1) % g == 0) cost[i] = b;
        else cost[i] = INF;
    }
    ssum[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        ssum[i] = ssum[i+1] + cost[i];
        if(ssum[i] >= INF) ssum[i] = INF;
    }
    psum[0] = cost[0];
    pcomb[0] = min(cost[0], 1LL * a);
    ll res = ssum[0];
    for(int i = 1; i <= n; i++) {
        res = min(res, ssum[i] + pcomb[i-1]);

        psum[i] = cost[i] + psum[i-1];
        if(psum[i] >= INF) psum[i] = INF;
        pcomb[i] = min(pcomb[i-1] + 1LL * a, psum[i]);
        if(pcomb[i] >= INF) pcomb[i] = INF;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    get_mobius_and_sieve();
    
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int d = -1; d <= 1; d++) put_list(num[0] + d);
    for(int d = -1; d <= 1; d++) put_list(num[n-1] + d);
    ll res = INF;
    for(int g : ps) res = min(res, solve(g));
    cout << res << endl;

}