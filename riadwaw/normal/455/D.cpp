#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 100100
using namespace std;
struct treap{
    int sz,pri,key;
    treap *lc,*rc,*par,*cor;
    treap(int _key=0):sz(1),key(_key),lc(NULL),rc(NULL),par(NULL),cor(NULL),pri(rand() + rand() % 2){}
};
treap pool[2*N];
int cnt=0;
treap *val[N],*ori=NULL;
inline int size(treap* x){
    return x?x->sz:0;
}
inline void pull(treap* x){
    if(x) x->sz=size(x->lc)+size(x->rc)+1;
}
treap* merge(treap* a,treap* b){
    if(a==NULL||b==NULL) return a?a:b;
    if(a->pri > b->pri){
        a->rc=merge(a->rc,b);
        if(a->rc) a->rc->par=a;
        pull(a);
        return a;
    }
    else{
        b->lc=merge(a,b->lc);
        if(b->lc) b->lc->par=b;
        pull(b);
        return b;
    }
}
void split(treap* x,int k,treap*& a,treap*& b){
    if(!x){
        a=NULL;
        b=NULL;
        return;
    }
    if(size(x->lc) < k){
        a=x;
        split(x->rc,k-size(x->lc)-1,a->rc,b);
        if(a->rc) a->rc->par=a;
        pull(a);
    }
    else{
        b=x;
        split(x->lc,k,a,b->lc);
        if(b->lc) b->lc->par=b;
        pull(b);
    }
}
int find_index(treap* x){
    bool left=true;
    int r=0;
    while(x!=NULL){
        if(left) r+=size(x->lc)+1;
        if(x->par&&x->par->rc==x) left=true;
        else left=false;
        x=x->par;
    }
    return r;
}
int cal(int r,int k){
    treap *a=val[k],*b;
    int ans=0;
    while(a!=NULL){
        if(find_index(a->cor)<=r){
            ans+=size(a->lc)+1;
            a=a->rc;
        }
        else a=a->lc;
    }
    return ans;
}
void upd(int l,int r){
    treap *a,*b,*c,*d;
    int k,vl,vr;
    split(ori,l-1,a,b);
    split(b,r-l+1,c,b);
    split(c,r-l,c,d);
    k=d->key;
    ori=merge(a,merge(d,merge(c,b)));
    vl=cal(l-1,k)+1;
    vr=cal(r,k);
    split(val[k],vl-1,a,b);
    split(b,vr-vl+1,c,b);
    split(c,vr-vl,c,d);
    val[k]=merge(a,merge(d,merge(c,b)));
}
inline int qry(int l,int r,int k){
    return cal(r,k)-cal(l-1,k);
}
    
int main(){
    srand(77547);
    int i,n,lastans=0,l,r,k=0,t,x,q;
    scanf("%d",&n);
    for(i=1;i<=n;i++) val[i]=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        ori=merge(ori,&(pool[cnt++]=treap(x)));
        val[x]=merge(val[x],&(pool[cnt++]=treap(x)));
        pool[cnt-1].cor=&pool[cnt-2];
        pool[cnt-2].cor=&pool[cnt-1];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&t,&l,&r);
        if(t==2) scanf("%d",&k);
        l=(l+lastans-1)%n+1;
        r=(r+lastans-1)%n+1;
        k=(k+lastans-1)%n+1;
        if(l>r) swap(l,r); 
        if(t==1){
            upd(l,r);
        }
        else{
            printf("%d\n",lastans=qry(l,r,k));
        }
    }
    return 0;
}