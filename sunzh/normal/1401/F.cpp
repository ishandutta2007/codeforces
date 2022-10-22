#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
int a[1000010];
int seg[4000010];
int rev[200];
void pushup(int p){
	seg[p]=seg[p<<1]+seg[p<<1|1];
}
int ls(int p,int k){
	if(rev[k]) return p<<1|1;
	else return p<<1;
}
int rs(int p,int k){
	if(rev[k]) return p<<1;
	else return p<<1|1;
}
void build(int p,int l,int r,int po){
	if(l==r){
		seg[p]=a[l];return ;
	}
	int mid=l+r>>1;
	build(ls(p,po),l,mid,po-1);
	build(rs(p,po),mid+1,r,po-1);
	pushup(p);
}
void update(int p,int l,int r,int po,int pos,int k){
	if(l==r){
		seg[p]=k;return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(ls(p,po),l,mid,po-1,pos,k);
	else update(rs(p,po),mid+1,r,po-1,pos,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R,int po){
	if(l>=L&&r<=R) return seg[p];
	int mid=l+r>>1;int res=0;
	if(L<=mid) res+=query(ls(p,po),l,mid,L,R,po-1);
	if(R>mid) res+=query(rs(p,po),mid+1,r,L,R,po-1);
	return res;
}
signed main(){
	n=read(),q=read();
	for(int i=1;i<=(1<<n);++i) a[i]=read();
	build(1,1,1<<n,n-1);
	while(q--){
		int op=read();
		switch(op){
			case 1:{
				int x=read(),k=read();
				update(1,1,(1<<n),n-1,x,k);
				break;
			}
			case 2:{
				int k=read();for(int j=k-1;j>=0;--j)rev[j]^=1;
				break;
			}
			case 3:{
				int k=read();
				rev[k]^=1;
				break;
			}
			case 4:{
				int l=read(),r=read();
				printf("%lld\n",query(1,1,1<<n,l,r,n-1));
				break;
			}
		}
	}
	return 0;
}