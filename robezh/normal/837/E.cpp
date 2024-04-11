#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = (int)1e6 + 5;
const ll INF = (ll)1e18;

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

ll x, y;
map<ll, ll> mp;

int main(){
    get_mobius_and_sieve();

    cin >> x >> y;
    ll nx = x;
    for(int i = 0; i < pms; i++) {
        while(nx % pm[i] == 0) {
            mp[pm[i]]++;
            nx /= pm[i];
        }
    }
    if(nx > 1) mp[nx]++;
    ll res = 0;
    while(y > 0) {
        ll mn_val = INF, mni = -1;
        for(const auto &p : mp) {
            if(p.second == 0) continue;
            if(y % (ll)p.first < mn_val) {
                mn_val = y % (ll)p.first;
                mni = p.first;
            }
        }
        if(mn_val == INF) mn_val = y;
        res += mn_val;
        y -= mn_val;
        ll gcd = __gcd(x, y);
        x /= gcd, y /= gcd;
        for(auto &p : mp) {
            if(p.second == 0) continue;
            while(gcd % p.first == 0) {
                p.second --;
                gcd /= p.first;
            }
        }
    }
    cout << res << endl;
}