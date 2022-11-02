#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register char c; while(!isdigit(c=getchar()));
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
}

const int max_N = 5e5 + 21;

int n,q,a[max_N],type,ans;

int seg[max_N<<2],pos[max_N];

#define ls(x) ((x)<<1)
#define rs(x) (ls(x)|1)
#define mid ((l+r)>>1)
#define lch ls(x),l,mid
#define rch rs(x),mid+1,r

inline void update(int x){
	seg[x]=std::__gcd(seg[ls(x)],seg[rs(x)]);
}

void build(int x,int l,int r){
	if(l==r){
		seg[x]=a[l];
		pos[l]=x;
		return;
	}
	build(lch),build(rch);
	update(x);
}

void modify(int x,int y){
	seg[pos[x]]=y;
	for(int i=pos[x]>>1;i;i>>=1)update(i);
}

int ql,qr,qx,qa,qk;

void query(int x,int l,int r){
	if(ql<=l&&r<=qr){
		qx=std::__gcd(qx,seg[x]);
		return;
	}
	if(ql<=mid)query(lch);
	if(qr>mid) query(rch);
}

void biS(int x,int l,int r){
	if(ql<=l&&r<=qr){
		if(l==r){
			qx=std::__gcd(qx,seg[x]);
			if(qa==-1&&(qx%qk)!=0)qa=l;
			return;
		}
		int tmp=std::__gcd(qx,seg[ls(x)]);
		if(!(tmp%qk))qx=tmp,biS(rch);
		else biS(lch);
	}
	else{
		if(ql<=mid)biS(lch);
		if(qr>mid) biS(rch);
	}
}

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("st.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	build(1,1,n);
	read(q);
	while(q--){
		read(type);
		if(type==1){
			read(ql),read(qr),read(qk);
			qx=0,qa=-1;
			biS(1,1,n);
			if(qa==-1)ans=1;
			else if(ql==qr||qa==qr)ans=1;
			else{
				ql=qa+1,qx=0;
				query(1,1,n);
				ans=!(qx%qk);
			}
			puts(ans?"YES":"NO");
		}
		else{
			int x,y;
			read(x),read(y);
			modify(x,y);
		}
	}
	return 0;
}