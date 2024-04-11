#include <stdio.h>
#include <string.h>
#include <algorithm>
#define TQ template<class Q>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

TQ inline void Scan(Q&x){
    char c;int f=1;
    while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
    for(x=0;c>47&&c<58;c=getchar())x=10*x+c-48;
    x*=f;
}

const int MAXN=1e5+5;

const bool LCT=0;
const bool ETT=1;

typedef struct node*star;
struct node{
    bool type;
    int siz,max,min,key;
    int add,id;
    star ch[2],p;
    inline int d(star rt);
    inline void updt();
    inline void down();
    inline bool check(int d);
    inline void add_it(int _add);
    inline void set_ch(star x,int d);
}pool[MAXN*3],*tail=pool;
inline star init_null(){
    star x=tail++;
    x->ch[0]=x->ch[1]=x->p=x;
    return x;
}
star nu=init_null();

inline int node::d(star rt=nu){
    if(rt==this)return -1;
    rep(i,0,1){
        if(p->ch[i]==this)return i;
    }
    return -1;
}
inline void node::set_ch(star x,int d){
    if(~d)ch[d]=x;x->p=this;
}
inline void node::updt(){
    siz=ch[0]->siz+1+ch[1]->siz;
    if(type==LCT)return;
    max=min=key;
    rep(i,0,1)if(ch[i]!=nu){
        if(max<ch[i]->max)max=ch[i]->max;
        if(min>ch[i]->min)min=ch[i]->min;
    } 
}
inline void node::add_it(int _add){
    key+=_add,min+=_add,max+=_add,add+=_add;
}
inline void node::down(){
    if(!add)return;
    rep(i,0,1){
        if(ch[i]!=nu)ch[i]->add_it(add);
    }
    add=0;
}

inline void rot(star x,star&rt=nu){
    star y=x->p;
    if(rt==y)rt=x;
    int d=x->d();   
    y->p->set_ch(x,y->d());
    y->set_ch(x->ch[d^1],d),y->updt();
    x->set_ch(y,d^1);
}
void pd(star x){
    if(x->type==LCT)return;
    if(x->p!=nu)pd(x->p);x->down();
} 
inline void splay(star x,star&rt=nu){
    pd(x);
    for(int d1,d2;~(d1=x->d(rt));rot(x,rt))
        if(~(d2=x->p->d(rt)))rot(d1^d2?x:x->p,rt);
    x->updt();  
}

inline star Access(star x){
    star y=x,t=nu;
    for(;x!=nu;t=x,x=x->p){
        splay(x),x->ch[1]=t,x->updt();
    }
    splay(y);
    return t;   
}
inline void change_p(star x,star y,star p){
    Access(p),splay(x),x->p=y;
}

inline int k_th(star x,int k){
    while(x!=nu){
        int siz=x->ch[1]->siz+1; 
        if(siz==k)return x-pool;
        int d=k>siz;if(d)k-=siz;
        x=x->ch[d^1]; 
    }
    return 0;
}

star st[MAXN<<1];

star build(int l,int r){
    if(l>r)return nu;
    int mid=(l+r)>>1;
    star cur=st[mid];
    cur->set_ch(build(l,mid-1),0);
    cur->set_ch(build(mid+1,r),1);
    cur->updt();
    return cur;
}

star rt;

int n,m,top;

inline bool node::check(int d){
    return min<=d&&max>=d;
}
int find(int d){
    if(d>rt->max)return 0;
    star x=rt;
    for(;;){
        x->down();
        if(x->ch[1]!=nu&&x->ch[1]->check(d)){
            x=x->ch[1];
        }
        else{
            if(x->key==d)return splay(x,rt),x-pool-n;
            x=x->ch[0];
        }
    }
}

inline void change_p(star y,star l,star r,int h){
    splay(l,rt),splay(r,l->ch[1]);
    star x=r->ch[0];
    x->p=nu,r->ch[0]=nu;
    r->updt(),l->updt();
    x->add_it(-h);
    for(;x->ch[0]!=nu;)x=x->ch[0];
    splay(x,rt),splay(y,rt);
    x->set_ch(y->ch[0],0);
    y->set_ch(x,0);
    x->updt(),y->updt(); 
}

star lct[MAXN],ett[MAXN<<1];

int son[MAXN],next[MAXN];

int p[MAXN],pre[MAXN],tai[MAXN];

void dfs(int x,int d){
    ett[x]->key=ett[x+n]->key=d;
    st[++top]=ett[x];
    lct[x]->siz=1;
    for(int y=son[x];y;y=next[y]){
        lct[y]->p=lct[x];
        dfs(y,d+1);
    }
    st[++top]=ett[x+n];
}

inline star new_node(bool type){
    star x=tail++;
    x->ch[0]=x->ch[1]=x->p=nu;
    x->type=type;
    return x;
}

void db(star x){
    if(x==nu)return;
    x->down();
    db(x->ch[0]);
    printf("(%d,%d) ",x-pool-n,x->key);
    db(x->ch[1]);
}

inline void Init(){
    Scan(n),Scan(m);
    rep(i,1,n){
        lct[i]=new_node(LCT);
    }
    rep(i,1,n)ett[i]=new_node(ETT);
    rep(i,1,n)ett[i+n]=new_node(ETT);
    rep(i,1,n){
        int k,j=0,x;
        for(Scan(k);k--;){
            Scan(x);
            if(!son[i])son[i]=j=x;
            else next[j]=x,pre[x]=j,j=x;
            p[x]=i;
        }
        tai[i]=j;
    }
    dfs(1,0);
    rt=build(1,top);
}

inline void del(int x,int px){
    if(!pre[x])son[px]=next[x];
    if(!next[x])tai[px]=pre[x];
    next[pre[x]]=next[x];
    pre[next[x]]=pre[x];
}

inline void add(int x,int px){
    pre[x]=tai[px],next[x]=0;
    next[tai[px]]=x,tai[px]=x;
    p[x]=px;
}

inline void Solve(){
    rep(cnt,1,m){   
        int opt,x,y,ans;
        Scan(opt);
        if(opt==1){
            Scan(x),Scan(y);
            Access(lct[x]);
            ans=lct[x]->siz;
            star lca=Access(lct[y]);
            ans+=lct[y]->siz;
            splay(lca);
            ans-=(lca->ch[0]->siz+1)<<1;
            printf("%d\n",ans);
        }
        else if(opt==2){
            Scan(x),Scan(y);        
            Access(lct[x]);
            int a=k_th(lct[x],2);
            int b=k_th(lct[x],y+1);
            change_p(lct[x],lct[b],lct[a]);
            
            star l,r;
            l=pre[x]?ett[pre[x]+n]:ett[p[x]];
            r=next[x]?ett[next[x]]:ett[p[x]+n];
            
            del(x,p[x]),add(x,b);
            
            change_p(ett[b+n],l,r,y-1);
        }
        else{
            Scan(x);
            ans=find(x);
            if(ans>n)ans-=n;
            printf("%d\n",ans);
        }
        
    }
}

int main(){
    Init(); Solve(); return 0;
}