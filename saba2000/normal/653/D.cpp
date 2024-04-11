#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[59][59], C[59][59], f[59][59];
ll fr[59], vs[59];
ll n, m, x;
bool bfs(ll X){
    for(ll i = 1; i <= n; i++)
        vs[i] = 0, fr[i] = 0;
    queue<ll> q;
    q.push(1);
    vs[1] = 1;
    while(q.size()){
        ll x = q.front();
        q.pop();
        for(ll i = 1; i <= n; i++){
            if(c[x][i] - f[x][i] >= X 
            && !vs[i]){
                vs[i] = 1;
                fr[i] = x;
                q.push(i);
            }
        }
    }
    if(!vs[n]) return 0;
    ll x = n;
    while(x != 1){
        f[fr[x]][x] += X;
        f[x][fr[x]] -= X;
        x = fr[x];
    }
    return 1;
}
ll flow(){
    ll Flow = 0;
    ll F = 5e7;
    while(F){
        if(bfs(F)) 
            Flow += F;
        else
            F /= 2;
    }
    return Flow;
    
}
main(){
    cin >> n >> m >> x;
    for(ll i = 1; i <= m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        C[a][b] = c;
    }
    long double lo = 0.0, hi = 1e6;
    while(hi - lo > 1e-11){
        long double mid = (lo + hi)/2;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                c[i][j] = (ll)((long double)C[i][j]/mid);
                f[i][j] = 0;
            }
        }
        if(flow() >= x)
            lo = mid;
       else hi = mid;
    }
    printf("%.9f",(double)lo * x);
    
}