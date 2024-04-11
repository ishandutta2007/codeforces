#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans, A[200009],c[200009],B[200009];
vector<ll> v[200009];
void dfs(ll x, ll p){
    if(p) c[x] = min(c[x], c[p]);
    for(ll y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        A[x] += A[y];
        B[x] += B[y];
    }
    ll d = min(A[x], B[x]);
    ans += d * c[x];
    A[x] -= d;
    B[x] -= d;
}
main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll x, y;

        cin >> c[i] >> x >> y;
        if(x != y){
            if(x == 0) A[i] = 1;
            else B[i] = 1;
        }
    }
    for(ll i = 1; i < n; i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    if(A[1] != B[1]) cout<<-1<<endl;
    else cout<<2*ans<<endl;


}