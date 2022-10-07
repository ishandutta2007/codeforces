#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
using namespace std;
struct node{
    ll val;
    node *L, *R;
    void upd(){
        this->val = max(this->L->val, this->R->val);
    }
};
void build(node *&x, ll l, ll r){
    x = new node();
    x->val = -1e18;
    if(l == r)
        return;
    build(x->L, l, mid);
    build(x->R, mid +1 , r);

}
void upd(node *&x, ll l, ll r, ll p, ll v){
     if(l > p || r < p)
        return;
    if(l == r)
    {
        x->val =max(x->val,v);
        return;
    }
    upd(x->L, l, mid,  p,v);
    upd(x->R, mid +1 ,r,p,v);

    x->upd();

}
ll cnt(node *&x, ll l, ll r, ll a, ll b){
    if(l > b || r < a) {
        return -1e18;
    }
    if(l >= a && r <= b)
        return x ->val;
    return max(cnt(x->L, l, mid,a,b) ,
                cnt(x->R, mid+1,r,a,b));
}
node *rt;


ll b[300009],h[300009];
ll n;
ll l[300009],r[300009];
ll dp[300009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    build(rt, 1, n);
    upd(rt, 1,n,1,0);
    for(ll i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
    }
    stack<ll> s;
    for(ll i = 1; i <= n; i++){
        while(s.size() && h[s.top()] > h[i]) s.pop();
        if(!s.size()) l[i] = 1;
        else l[i] = s.top() + 1;
        s.push(i);
    }
    while(s.size()){
        s.pop();
    }
    for(ll i = n; i >= 1; i--){
        while(s.size() && h[s.top()] > h[i]) s.pop();
        if(!s.size()) r[i] = n;
        else r[i] = s.top() -1;
        s.push(i);
    }
    while(s.size()){
        s.pop();
    }
    ll ans = -1e18;
    for(ll i = 1; i <= n; i++){
        dp[i] = cnt(rt, 1, n, l[i], n) + b[i];
        upd(rt, 1, n, min(n,r[i]+1), dp[i]);
        if(r[i] == n){
            ans = max(ans, dp[i]);
        }
    }
    cout<<ans<<endl;
}