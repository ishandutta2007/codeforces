#include<bits/stdc++.h>
#define A this
#define B this->L
#define C this->R
using namespace std;
const int mX = 1e6+4;
struct node{
    int mx = 0, lz = 0;
    node *L, *R;
    void upd(){
        if(B)
            A->mx = max(B->mx, C->mx);
    }
    void lzu(){
        A->mx += A->lz;
        if(B) B->lz += A->lz;
        if(C) C-> lz +=A->lz;
        A->lz = 0;
    }
};
void build(node *&x, int l, int r){
    x = new node();
    if(l == r) {
        return;
    }
    int mid = (l+r)/2;
    build(x->L,l,mid);
    build(x->R,mid+1,r);
}
void upd(node *&x,int l, int r, int a, int b, int d){

    x->lzu();
    if(l > b || r < a) return;
    if(l >= a && r <= b){
        x->lz += d;
        x->lzu();
        return;
    }
    int mid = (l + r)/2;
    upd(x->L,l,mid,a,b,d);
    upd(x->R,mid+1,r,a,b,d);
    x->upd();
}
int cnt(node *&x, int l, int r){
    x->lzu();
    if(l == r) return l;
    int mid = (l+r)/2;
    x->R->lzu();
    if(x->R->mx > 0) return cnt(x->R, mid+1,r);
    else return cnt(x->L, l, mid);
}
int a[300009], b[300009];
main(){
    int n, m;
    node *rt;

    cin >> n >> m;
    build(rt,1,mX);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        upd(rt,1,mX,1,a[i],+1);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        upd(rt,1,mX,1,b[i], -1);

    }
    int q;
    cin >> q;
    while(q--){
        int t,p,v;
        scanf("%d %d %d",&t,&p,&v);
        if(t==1){
            upd(rt,1,mX,1,a[p], -1);
            a[p] = v;
            upd(rt,1,mX,1,a[p], +1);
        }
        else{
            upd(rt,1,mX,1,b[p],+1);
            b[p] = v;
            upd(rt,1,mX,1,b[p], -1);
        }
        rt->lzu();
        if(rt->mx<= 0)printf("-1\n"); else
        printf("%d\n",cnt(rt,1, mX));
    }
}