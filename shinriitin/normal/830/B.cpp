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

#define max_N 100005
#define Siz(x) ((x)?x->siz:0)
#define Min(x) ((x)?x->mx:233333)

typedef struct node*star;

struct node{
	int x,mx,siz;
	star ch[2];
	inline void update(){
		mx=min(x,min(Min(ch[0]),Min(ch[1])));
		siz=Siz(ch[0])+1+Siz(ch[1]);
	}
}pool[max_N];

star rt,tail=pool;

inline star new_node(int key){
	star x=tail++;
	x->x=x->mx=key;
	x->siz=1;
	x->ch[0]=x->ch[1]=NULL;
	return x;
}

star merge(star x,star y){
	if(!x||!y)return x?x:y;
	if(1ll*rand()*(Siz(x)+Siz(y))<1ll*Siz(x)*RAND_MAX){
		x->ch[1]=merge(x->ch[1],y);
		return x->update(),x;
	}
	else{
		y->ch[0]=merge(x,y->ch[0]);
		return y->update(),y;
	}
}

typedef pair<star,star>pss;

pss split(star x,int k){
	if(!x||!k)return pss(0,x);
	pss o;
	if(Siz(x->ch[0])>=k){
		o=split(x->ch[0],k);
		x->ch[0]=o.second,o.second=x;
	}
	else{
		o=split(x->ch[1],k-Siz(x->ch[0])-1);
		x->ch[1]=o.first,o.first=x;
	}
	return x->update(),o;
}

int calc(star x,int key){
	if(Min(x->ch[0])==key)return calc(x->ch[0],key);
	if(x->x==key)return Siz(x->ch[0])+1;
	return Siz(x->ch[0])+1+calc(x->ch[1],key);
}

int n,a[max_N];

star build(int l,int r){
	if(l>r)return NULL;
	int mid=(l+r)>>1;
	star x=new_node(a[mid]);
	x->ch[0]=build(l,mid-1);
	x->ch[1]=build(mid+1,r);
	return x->update(),x;
}

long long ans;

int main(){
	n=gint();
	for(int i=1;i<=n;++i)a[i]=gint();
	rt=build(1,n);
	for(int i=1,k;i<=n;++i){
		k=calc(rt,Min(rt));
		ans+=k;
		pss o=split(rt,k);
		pss o1=split(o.first,k-1);
		rt=merge(o.second,o1.first);
	}
	printf("%I64d\n",ans);
	return 0;
}