#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
struct val{
    long long w, wx;
};
val com(val a, val b){
    a.w += b.w;
    a.wx += b.wx;
    return a;
}
struct node{
    val V;
    node *L, *R;
    void upd(){
        this->V = com(this->L->V, this->R->V);
    }
};
long long W[200009], X[200009];
void build(node *&x, long long l, long long r){
    x = new node();
    if(l == r){
        x -> V.w = W[l];
        x -> V.wx = W[l] * X[l] % mod;
        return;
    }
    long long mid = (l + r)/2;
    build(x->L, l, mid);
    build(x->R, mid+1, r);
    x -> upd();
}
void upd(node *&x, long long l, long long r, long long p){
    if(p < l || p > r) return;
    if(l == r){
         x -> V.w = W[l];
        x -> V.wx = W[l] * X[l] % mod;
        return;
    }
    long long mid = (l + r)/2;
    upd(x->L, l, mid, p);
    upd(x->R, mid+1, r, p);
    x -> upd();
}
long long cntpos(node *&x, long long l, long long r, long long S){
    if(l == r) return l;
    long long Sl = x->L->V.w;
    long long mid = (l + r)/2;
    if(Sl >= S) return cntpos(x->L, l, mid, S);
    return cntpos(x->R, mid+1, r, S - Sl);
}
val zer;
long long CNTW(node *&x, long long l, long long r, long long a, long long b){
    if(l >= a && r <= b) return x->V.w;
    if(l > b || r < a) return 0;
    long long mid =(l+r)/2;
    return CNTW(x->L, l, mid, a, b)+
               CNTW(x->R, mid+1,r,a,b);
}
long long CNTWX(node *&x, long long l, long long r, long long a, long long b){
    if(l >= a && r <= b) return x->V.wx;
    if(l > b || r < a) return 0;
    long long mid =(l+r)/2;
    return CNTWX(x->L, l, mid, a, b)+
               CNTWX(x->R, mid+1,r,a,b);
}

node *rt;
long long n;
long long ww(long long l, long long r){
    if(l  > r) return 0;
    return CNTW(rt, 1, n, l, r);
}
long long wwx(long long l, long long r){
    if(l > r) return 0;
    return CNTWX(rt, 1, n, l, r);
}
main(){
    long long q;
    cin >> n >> q;
    for(long long i = 1; i <= n; i++){
        scanf("%lld",&X[i]);
        X[i] -= i;
    }
    for(long long i = 1; i <= n; i++){
       scanf("%lld",&W[i]);
    }
    build(rt, 1, n);
    while(q -- ){
        long long x, y;
       scanf("%lld",&x);
       scanf("%lld",&y);
        if(x < 0){
            x = -x;
            W[x] = y;
            upd(rt, 1, n, x);
            continue;
        }
        long long s1 = ww(1, x - 1);
        long long s2 = ww(x, y);
        long long k = cntpos(rt, 1, n, s1 + (s2 + 1)/2);
        long long ans = ((ww(x, k) % mod*X[k]%mod - wwx(x, k) + wwx(k, y) - ww(k, y) % mod*X[k])% mod + mod)% mod ;
        cout << ans << endl;
    }

}