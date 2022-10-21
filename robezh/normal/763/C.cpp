#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int mod, n;

ll gm(ll x) {
    return (x % mod + mod) % mod;
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll inv(ll x) {
    return fp(x, mod - 2);
}

int count(ll d, vector<ll> &a) {
    map<ll, int> mp;
    int res = 0;
    for(int i = 0; i < a.size(); i++) {
        res += mp[gm(a[i] - d)] + mp[gm(a[i] + d)];
        mp[a[i]]++;
    }
    return res;
}

P solve(vector<ll> num) {
    int n = num.size();
    if(n == 0) return {0, 1};
    if(n == 1) return {num[0], 1};
    ll dif = gm(num[1] - num[0]);
    int cnt = count(dif, num);
//    cout << "dif: " << dif << endl;
//    cout << "cnt: " << cnt << endl;
    ll ans_d = gm(dif * inv(n - cnt));
    map<ll, int> mp;
    for(int i = 0; i < n; i++) mp[num[i]]++;
    ll cur = num[0];
    while(true) {
        ll nxt = gm(cur - ans_d);
        if(!mp.count(nxt)) break;
        cur = nxt;
    }
    for(int i = 0; i < n; i++) {
        if(!mp.count(gm(cur + ans_d * i))) return {-1, -1};
    }
    return {cur, ans_d};
}

vector<ll> a;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> mod >> n;
    a.resize(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(2 * n < mod + 1) {
        P p = solve(a);
        if(p.first == -1) cout << "-1" << endl;
        else cout << p.first << " " << p.second << endl;
    }
    else {
        map<ll, int> mp;
        for(int i = 0; i < n; i++) mp[a[i]]++;
        vector<ll> b;
        for(int i = 0; i < mod; i++) if(!mp.count(i)) b.push_back(i);
        P p = solve(b);
        if(p.first == -1) cout << "-1" << endl;
        else cout << gm(p.first + (mod - n) * p.second) << " " << p.second << endl;
    }
}