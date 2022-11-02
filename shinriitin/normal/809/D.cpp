#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 300005
#define inf 0x7f7f7f7f

typedef struct node*star;

struct node{
	int siz,dp,tag;
	star p,ch[2];
	inline int d(){
		if(p->ch[0]==this)return 0;
		if(p->ch[1]==this)return 1;
		return -1;
	}
	inline void set_ch(star x,int d){
		if(~d)ch[d]=x; x->p=this;
	}
	inline void add(int x){
		dp+=x,tag+=x;
	}
	inline void update(){
		siz=ch[0]->siz+1+ch[1]->siz;
	}
	inline void putdown(){
		if(tag)ch[0]->add(tag),ch[1]->add(tag);
		tag=0;
	}
}pool[max_N],*tail=pool;

inline void rot(star x,star&rt){
	star y=x->p;
	int d=x->d(),d1=y->d();
	if(rt==y)rt=x;
	y->p->set_ch(x,d1);
	y->set_ch(x->ch[d^1],d);
	x->set_ch(y,d^1);
	y->update();
}

inline star init_null(){
	star x=tail++;
	x->dp=x->tag=x->siz=0;
	x->p=x->ch[0]=x->ch[1]=x;
	return x;
}

star null=init_null();

inline star new_node(){
	star x=tail++;
	x->dp=inf,x->tag=0;
	x->siz=1;
	x->p=x->ch[0]=x->ch[1]=null;
	return x;
}

void pd(star x,star rt){
	if(x!=rt)pd(x->p,rt); x->putdown();
}

inline void splay(star x,star&rt){
	pd(x,rt);
	for(star y;rt!=x;rot(x,rt))
		if(rt!=(y=x->p))rot(x->d()^y->d()?x:y,rt);
	x->update();
}

int rk(star x,int k){
	if(x==null)return 0;
	if(x->dp==k)return x->ch[0]->siz+1;
	x->putdown();
	int d=k>x->dp;
	return (d?x->ch[0]->siz+1:0)+rk(x->ch[d],k);
}

star kth(star x,int k){
	if(x->ch[0]->siz+1==k)return x;
	x->putdown();
	int d=k>x->ch[0]->siz+1;
	if(d)k-=x->ch[0]->siz+1;
	return kth(x->ch[d],k);
}

int n,l[max_N],r[max_N],ans;

star rt,t[max_N];

void display(star x){
	if(x==null)return;
	display(x->ch[0]);
	printf("%d ",x->dp);
	display(x->ch[1]);
}

int main(){
//	freopen("input.txt","r",stdin);
	n=gint();
	for(int i=1;i<=n;++i)l[i]=gint(),r[i]=gint();
	for(int i=1;i<=n+1;++i)t[i]=new_node();
	for(int i=n;i;--i)t[i]->set_ch(t[i+1],1),t[i]->update();
	rt=t[1],rt->dp=0;
	for(int i=1;i<=n;++i){
		int k1=rk(rt,l[i]-1),k2=rk(rt,r[i]-1);
		star x=kth(rt,k1),y=kth(rt,k2+1),z;
		splay(x,rt),splay(y,x->ch[1]);
		y->dp=l[i];
		if((z=y->ch[0])!=null){
			z->add(1);
			z=kth(z,z->siz);
			splay(z,y->ch[0]);
			z->set_ch(y->ch[1],1),z->update();
			y->set_ch(z,1),y->set_ch(null,0),y->update();
		}
//		display(rt),puts("");
	}
	ans=rk(rt,inf-1);
	printf("%d\n",ans-1);
	return 0;
}