#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const int N = 505;
const ll mod = 998244353;

int n;
ll num[N];
map<ll, int> mp_small, mp_large;

ll gcd(ll x, ll y){
    return x == 0 ? y : gcd(y % x, x);
}

ll spower(ll x, int p){
    ll res = 1;
    while(p > 0) res *= x, p--;
    return res;
}

ll bs_power(ll x, int p){
    ll l = 1, r, mid;
    if(p == 2) r = (ll)1e9 + (ll)5e8;
    else if(p == 3) r=  1300000;
    else r = 38000;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(spower(mid, p) > x) r = mid;
        else l = mid;
    }
    if(spower(l, p) == x) return l;
    else return -1;
}

P get(ll x){
    for(int i = 4; i >= 2; i--){
        ll now = bs_power(x, i);
        if(now != -1) return {now, i};
    }
    return {-1,-1};
}


int main() {

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];

    for(int i = 0; i < n; i++){
        P p = get(num[i]);
        if(p.first != -1) mp_small[p.first] += p.second;
        else{
            mp_large[num[i]] ++;
        }
    }
    for(auto it = mp_large.begin(); it != mp_large.end();){
        bool good = true;
        for(int i = 0; i < n; i++){
            ll g = gcd(it->first, num[i]);
            if(g != it->first && g != 1){
                ll now = it->first;
                now /= g;
                mp_small[now] += it->second;
                mp_small[g] += it->second;
                good = false;
                it = mp_large.erase(it);

                break;
            }
        }
        if(good) it++;
    }
    ll res = 1;
    for(auto p : mp_small){
        res *= (p.second + 1);
        res %= mod;
    }
    for(auto p : mp_large){
        res *= (p.second + 1) * (p.second + 1) % mod;
        res %= mod;
    }
    cout << res << endl;


}