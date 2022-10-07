#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll val, lz, tm;
    node *L, *R;
    void upd(){
        this->val = (this->L->val + this->R->val);
    }
    void lzu(int L){
        if(!this->tm) return;
        if(!this->lz) this->val = 0;
         else
        this->val = L;
        if(this->L) {
            if(this->tm > this->L->tm)
                this->L->tm = this->tm,
                this->L->lz = this->lz;
             if(this->tm > this->R->tm)
                this->R->tm = this->tm,
                this->R->lz = this->lz;
        }
        this->lz = 0;
        this->tm = 0;
    }
};
void build(node *&x, ll l, ll r){
    x = new node();
    x->val = 0;
    x->lz = 0;
    x->tm = 0;
    if(l == r)
        return;

    ll mid = (l + r)/2;
    build(x->L, l, mid);
    build(x->R, mid +1 , r);
    x->upd();

}
ll T;
void upd(node *&x, ll l, ll r, ll a, ll b, ll c){
    x->lzu(r-l+1);
     if(l > b || r < a)
        return;
    if(l >= a && r <= b)
    {
        x->lz = c;
        x->tm  = T;
        x->lzu(r-l+1);
        return;
    }
    ll mid = (l + r)/2;
    upd(x->L, l, mid, a,b,c);
    upd(x->R, mid +1 ,r, a,b,c);

    x->upd();

}
ll cnt(node *&x, ll l, ll r, ll a, ll b){
    x->lzu(r-l+1);
    if(l > b || r < a) {
        return 0;
    }
    if(l >= a && r <= b)
        return x ->val;
    ll mid = (l + r)/2;
    return cnt(x->L, l, mid,a,b) +
                cnt(x->R, mid+1,r,a,b);
}
int l[200009],r[200009];
void solve(){
    int n,q;
    node *rt;
    cin >> n >> q;

    build(rt, 1, n);
    string S,F;
    cin >> S>> F;
    for(int i = 1; i <= n; i++){
        if(F[i-1] == '0') ++T,upd(rt, 1,n,i,i, 0);
        else ++T, upd(rt, 1,n,i,i,1);
    }
    for(int i = 1; i <= q; i++){
        cin >> l[i] >> r[i];
    }
    for(int i = q; i >= 1; i--){
        ll sm = cnt(rt,1,n,l[i],r[i]);
        if(sm *2 == (r[i] - l[i]+1)){
            cout<<"NO"<<endl;
            return;
        }
        else{
            if(sm *2  < (r[i] - l[i]+1)){
                ++T;
                upd(rt,1,n,l[i],r[i],0);

            }
            else{
                ++T;
                upd(rt,1,n,l[i],r[i],1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(S[i-1] - '0' != cnt(rt,1,n,i,i)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}