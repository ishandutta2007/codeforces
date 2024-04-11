#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 200005
using namespace std;

int n,k,a;

typedef struct node*star;

struct node{
    int l,r,sz,siz;
    star ch[2],p;
    inline void updt(){
        int x=(r-l+2)/(a+1);
        sz=ch[0]->sz+x+ch[1]->sz;
        siz=ch[0]->siz+1+ch[1]->siz;
    }
    inline int d(){
        if(p->ch[0]==this)return 0;
        if(p->ch[1]==this)return 1;
        return -1;
    }
    inline void set_ch(star x,int d){
        if(~d)ch[d]=x; x->p=this;
    }
}pool[MAXN];

star tail=pool;

inline star null(){
    star x=tail++;
    x->ch[0]=x->ch[1]=x->p=x;
    x->l=0,x->r=-1;
    return x;
}

star nu=null();

inline star new_node(int l,int r){
    star x=tail++;
    x->ch[0]=x->ch[1]=x->p=nu;
    x->l=l,x->r=r;
    return x->updt(),x;
}

star rt;

inline void rot(star x,star&rt){
    star y=x->p;
    int d=x->d();
    if(rt==y)rt=x;
    y->p->set_ch(x,y->d());
    y->set_ch(x->ch[d^1],d),y->updt();
    x->set_ch(y,d^1);
}

inline void splay(star x,star&rt){
    int d1,d2;
    for(;d1=x->d(),x!=rt;rot(x,rt))
        if(d2=x->p->d(),x->p!=rt){
            rot(d1^d2?x:x->p,rt);
        }
    x->updt();
}

inline star k_th(star x,int k){
    if(x->l<=k&&x->r>=k)return x;
    int d=k>x->r;
    return k_th(x->ch[d],k);
}

inline star kth(star x,int k){
    if(x->ch[0]->siz>=k)return kth(x->ch[0],k);
    return (k-=x->ch[0]->siz+1)?kth(x->ch[1],k):x;
}

int m;

int main(){
    scanf("%d%d%d",&n,&k,&a);
    rt=new_node(1,n);
    scanf("%d",&m);
    for(int i=1,x;i<=m;++i){
        scanf("%d",&x);
        star y=k_th(rt,x);
        splay(y,rt);
        int t1=y->l<x,t2=y->r>x;
        if(t1&&t2){
            star L=new_node(y->l,x-1);
            star R=new_node(x+1,y->r);
            R->set_ch(y->ch[1],1);
            R->updt();
            L->set_ch(y->ch[0],0);
            L->set_ch(R,1);
            L->updt();
            rt=L;
        }
        else if(t1){
            star L=new_node(y->l,x-1);
            L->set_ch(y->ch[0],0);
            L->set_ch(y->ch[1],1);
            L->updt();
            rt=L;
        }
        else if(t2){
            star R=new_node(x+1,y->r);
            R->set_ch(y->ch[0],0);
            R->set_ch(y->ch[1],1);
            R->updt();
            rt=R;
        }
        else{
            if(y->ch[0]!=nu){
                rt=y->ch[0];
                splay(kth(rt,rt->siz),rt);
                rt->set_ch(y->ch[1],1);
            }
            else if(y->ch[1]!=nu){
                rt=y->ch[1];
                splay(kth(rt,1),rt);
                rt->set_ch(y->ch[0],0);
            }
            else rt=nu;
            rt->p=nu,rt->updt();
        }
        if(rt->sz<k){
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}