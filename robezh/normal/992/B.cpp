#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l,r,x,y;
bool p[100050];
vector<int> pr;
ll fac[100050];
map<int, int> mp;
set<ll> res;
int ans = 0, fasize = 0;

ll gcd(ll a, ll b){
    return a == 0 ? b : gcd(b%a, a);
}

int get_ans(){
    int ans = 0;
    for(ll i = l; i <= r; i++){
        for(ll j = l; j <= r; j++){
            if(gcd(i, j) == x && i * j / gcd(i,j) == y){
                ans ++;
            }
        }
    }
    return ans;
}

int main(){
    fill(p, p+100050, true);
    for(int i = 2; i <= 100050; i++){
        if(p[i]) for(int j = 2*i; j <= 100050; j+=i) p[j] = false;
    }
    for(int i = 2; i <= 100050; i++){if(p[i]) pr.push_back(i);}
    cin >> l >> r >> x >> y;
    ll xr = x, yr = y;
    if(y % x != 0) return !printf("0");
    for(int prx : pr){
        while(yr % prx == 0){mp[prx]++; yr /= prx;}
    }
    if(yr > 1) mp[yr] ++;
    for(int prx : pr){
        while(xr % prx == 0){mp[prx]--; if(mp[prx] == 0) mp.erase(prx); xr /= prx;}
    }
    if(xr > 1) mp[xr] --;
    for(auto p : mp){
        fac[fasize] = 1;
        for(int i = 0; i < p.second; i++) fac[fasize] = 1LL * fac[fasize] * p.first;
        fasize++;
    }
    for(int i = 0; i < (1 << fasize); i++){
        ll a = 1, b;
        for(int j = 0; j < fasize; j++){
            if(i & (1 << j)) a *= fac[j];
        }
        a = 1LL * x * a;
        b = 1LL * x * y / a;
        if(a >= l && b >= l && a <= r && b <= r) res.insert(a);
    }
    //for(int x : res) cout << x << " ";
    //cout << endl;
    cout << res.size() << endl;
}