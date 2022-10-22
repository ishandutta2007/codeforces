#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m;
char s[100010];
struct node{
	int s[30];
	int tag;
}seg[400010];
void pushup(int p){
	for(int i=1;i<=26;++i) seg[p].s[i]=seg[p<<1].s[i]+seg[p<<1|1].s[i];
}
void pushdown(int p,int l,int r){
	if(seg[p].tag){
		int mid=l+r>>1;
		memset(seg[p<<1].s,0,sizeof(seg[p<<1].s));
		memset(seg[p<<1|1].s,0,sizeof(seg[p<<1|1].s));
		seg[p<<1].s[seg[p].tag]=mid-l+1;
		seg[p<<1|1].s[seg[p].tag]=r-mid;
		seg[p<<1].tag=seg[p<<1|1].tag=seg[p].tag; 
		seg[p].tag=0;
	}
}
void build(int p,int l,int r){
	if(l==r){
		seg[p].s[s[l]-'a'+1]=1;
		seg[p].tag=s[l]-'a'+1;
		return ;
	} 
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		for(int i=1;i<=26;++i) seg[p].s[i]=0;
		seg[p].s[k]=r-l+1;
		seg[p].tag=k;
		return ;
	}
	int mid=l+r>>1;
	pushdown(p,l,r);
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
node query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return seg[p];
	pushdown(p,l,r);
	int mid=l+r>>1;
	node res;
	memset(res.s,0,sizeof(res.s));
	if(L<=mid){
		node tmp=query(p<<1,l,mid,L,R);
		for(int i=1;i<=26;++i) res.s[i]+=tmp.s[i];
	} 
	if(mid<R){
		node tmp=query(p<<1|1,mid+1,r,L,R);
		for(int i=1;i<=26;++i) res.s[i]+=tmp.s[i]; 
	}
	return res;
}
void print(int p,int l,int r){
	if(l==r){
		putchar(seg[p].tag+'a'-1);
		return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	print(p<<1,l,mid);
	print(p<<1|1,mid+1,r);
}
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),k=read();
		node tmp=query(1,1,n,l,r);
		if(k!=0){
			for(int j=1;j<=26;++j){
				if(tmp.s[j]) update(1,1,n,l,l+tmp.s[j]-1,j);
				l+=tmp.s[j];
			} 
		}
		else{
			for(int j=26;j>=1;--j){
				if(tmp.s[j]) update(1,1,n,l,l+tmp.s[j]-1,j);
				l+=tmp.s[j];
			}
		}
	}
	print(1,1,n);
	return 0;
}