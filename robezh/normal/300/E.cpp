#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = (int)1e7 + 50;

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

int n;
int sum[M];
ll cnt[M];

ll check(ll x) {
    for(int pi = 0; pi < pms; pi++) {
        int px = pm[pi];
        ll tc = 0;
        for(ll d = px; d <= x; d *= px) tc += x / d;
        if(tc < cnt[px]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    get_mobius_and_sieve();
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a; sum[a]++;
    }
    for(int i = M - 2; i >= 0; i--) sum[i] += sum[i+1];
    int tc = 0;
    for(int i = 2; i < M; i++) {
        if(!p[i]) continue;
        for(int j = i; j < M; j += i) {
            int c = 0, x = j;
            while(x % i == 0) {
                x /= i;
                c++;
            }
            cnt[i] += 1LL * c * sum[j];
        }
    }
    ll l = 0, r = (ll)1e13, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}