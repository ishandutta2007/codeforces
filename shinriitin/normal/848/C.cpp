#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

const int max_N=1e5;

int n,m,a[max_N+21];

std::set<int>set[max_N+21];

typedef struct node*star;

typedef long long ll;

struct node{
	ll val;
	star ch[2];
	node():val(0){memset(ch,0,sizeof(ch));}
};

star pool;

int tail;

inline star new_node(){
	if(!tail)pool=new node[max_N*10],tail=max_N*10;
	return pool+(--tail);
}

void modify(star&rt,int l,int r,int pos,int val){
	if(!rt)rt=new_node();
	rt->val+=val;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos>mid)return modify(rt->ch[1],mid+1,r,pos,val);
	return modify(rt->ch[0],l,mid,pos,val);
}

ll query(star rt,int l,int r,int ll,int rr){
	if(!rt)return 0;
	if(l==ll&&r==rr)return rt->val;
	int mid=(l+r)>>1;
	if(rr<=mid)return query(rt->ch[0],l,mid,ll,rr);
	if(ll>mid)return query(rt->ch[1],mid+1,r,ll,rr);
	return query(rt->ch[0],l,mid,ll,mid)+query(rt->ch[1],mid+1,r,mid+1,rr);	
}

star rt[max_N+21];

inline void modify(int x,int y,int val){
	for(int i=x;i&&i<=n;i+=i&-i)modify(rt[i],0,n,y,val);	
}

inline ll query(int l,int r){
	ll res1=0,res2=0;		
	for(int i=r;i;i-=i&-i)res1+=query(rt[i],0,n,l,r);
	for(int i=l-1;i;i-=i&-i)res2+=query(rt[i],0,n,l,r);
	return res1-res2;
}

inline void del(int op1){
	auto it=set[a[op1]].find(op1);
	int pre=*--it; ++it;
	modify(op1,pre,pre-op1);
	if(++it!=set[a[op1]].end()){
		int nex=*it;
		modify(nex,op1,op1-nex);
		modify(nex,pre,nex-pre);
	}
	--it;
	set[a[op1]].erase(it);
}

inline void add(int op1){
	set[a[op1]].insert(op1);
	auto it=set[a[op1]].find(op1);
	int pre=*--it; ++it;
	modify(op1,pre,op1-pre);
	if(++it!=set[a[op1]].end()){
		int nex=*it;
		modify(nex,op1,nex-op1);
		modify(nex,pre,pre-nex);	
	}
	--it;
}

int main(){
	read(n),read(m);
	for(int i=1;i<=n;++i){
		set[i].insert(0);
		read(a[i]);
		set[a[i]].insert(i);
	}
	for(int i=1;i<=n;++i){
		for(auto it=set[i].begin();;){
			int pre=*it;
			if(++it==set[i].end())break;
			int nex=*it;
			modify(nex,pre,nex-pre);
		}
	}
	while(m--){
		int opt,op1,op2;
		read(opt),read(op1),read(op2);
		if(opt==1){
			del(op1);
			a[op1]=op2;
			add(op1);
		}
		else{
			printf("%I64d\n",query(op1,op2));
		}
	}
	return 0;
}