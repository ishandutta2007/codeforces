#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[5009],g[5009];
ll f[5009],s[5009],h[5009];
ll mod = 1e9 + 7;
main(){
    ll n, m;
    cin >> n >> m;
    for(ll i =1; i <= n; i++){
        cin >> f[i];
        g[f[i]].push_back(i);
    }
    for(ll i = 1; i <= m; i++){
        cin >> s[i] >> h[i];
        if(g[s[i]].size() >= h[i])
            v[s[i]].push_back(i);
    }
    long long ans = 0, nc = 0;
    for(ll i = 0; i <= m; i++){
        ll NC = 0, ANS = 1;
        ll I;
        if(i && g[s[i]].size() < h[i]) continue;
        if(i) I = g[s[i]][h[i] - 1],NC=1;
            else I = 0;
        for(ll j = 1; j <= n; j++){
            if(j == s[i]){
                ll t = 0;
                for(ll x : v[j])
                    if(x != i &&
                       g[j][g[j].size()-h[x]] > I)
                        t++;
                if(t) NC ++, ANS = ANS * t % mod;
            }
            else{
                ll a  = 0, b =0 , ab = 0;
                for(ll x : v[j]){
                    if(g[j][h[x] - 1] <= I) a++;
                    if(g[j][g[j].size() - h[x]] > I) b++;
                    if(g[j][h[x] - 1] <= I && g[j][g[j].size() - h[x]] > I)
                        ab++, a--, b--;
                }
                if(ab > 1 || (ab > 0 && (a > 0 || b > 0)) || (a > 0 && b > 0))
                {
                    NC += 2;
                    ANS = ANS * ((ab + a) * (ab + b) - ab) % mod;
                }
                else if(ab || a || b){
                    NC ++;
                    ANS = ANS * (a +b + 2*ab) % mod;
                }
            }
        }

        if(NC == nc) ans =(ans + ANS) % mod;
        else if(NC > nc) nc = NC, ans = ANS % mod;
    }
    cout << nc <<" "<<ans << endl;



}
/*
5 5
1 2 2 1 2
1 1
1 2
2 1
2 2
2 3

*/