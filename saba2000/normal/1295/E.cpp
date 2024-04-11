#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
using namespace std;
int p[200009];
int w[200009];
ll a[200009];
struct node {
    ll mn, lz;
    node *L, *R;
    void upd(){
        this->mn = min(this->L->mn, this->R->mn);
    }
    void lzu(){
        if(this->L){
        this->L->lz += this->lz;
        this->R->lz += this->lz;
        }
        this->mn += this->lz;
        this->lz = 0;
    }

};
node *rt;
void build(node *&x, ll l, ll r){
    x = new node();
    if(l == r) {
        return;
    }
    build(x->L,l,mid);
    build(x->R,mid+1,r);

}
void upd(node *&x, ll l, ll r, ll a, ll b, ll v){
    x->lzu();
    if(r < a || l > b) return;
    if(l >= a && r <= b){
        x->lz += v;
        x->lzu();
        return;
    }
    upd(x->L,l,mid,a,b,v);
    upd(x->R,mid+1,r,a,b,v);
    x->upd();
}

main(){
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        w[p[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        int XX;
        scanf("%d", &XX);
        a[i] = XX;
    }
    build(rt, 1,n-1);
    for(ll i = 1; i <= n; i++){
        upd(rt, 1, n-1,i, n - 1, a[i]);

    }
    ll ans = a[1];
    for(int i = 0; i <= n; i++){
        if(i){ll s = w[i];
        upd(rt,1,n-1,s, n-1, -a[s]);
        upd(rt,1,n-1,1,s-1, a[s]);}
                ans = min(ans, (rt->mn));
    }
    cout<<ans<<endl;
}