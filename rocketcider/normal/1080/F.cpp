#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxk=3e5+10,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct node{
	int l,r,p;
	inline bool operator<(const node &k)const{return l<k.l;}
}a[maxk];
int cnt,k,m,n,rt[maxk];
struct segment_tree{
	int ls,rs,mx;
}t[maxk*50];
void insert(int &p,int l,int r,int k,int v){
	t[++cnt]=t[p];
	p=cnt;
	if(l==r){
		ckmin(t[p].mx,v);
		return;
	}
	ri mid=l+r>>1;
	k<=mid?insert(t[p].ls,l,mid,k,v):insert(t[p].rs,mid+1,r,k,v);
	t[p].mx=max(t[t[p].ls].mx,t[t[p].rs].mx);
}
int query(int p,int l,int r,int ql,int qr){
	if(!p)return INT_MAX;
	if(ql<=l&&r<=qr)return t[p].mx;
	ri mid=l+r>>1,ret=0;
	if(ql<=mid)ckmax(ret,query(t[p].ls,l,mid,ql,qr));
	if(qr>mid)ckmax(ret,query(t[p].rs,mid+1,r,ql,qr));
	return ret;
}
int main(){
	n=qr(),m=qr(),k=qr();
	for(ri i=1;i<=k;++i)a[i].l=qr(),a[i].r=qr(),a[i].p=qr();
	sort(a+1,a+k+1);
	t[0].mx=INT_MAX;
	for(ri i=k;i;--i){
		rt[i]=rt[i+1];
		insert(rt[i],1,n,a[i].p,a[i].r);
	}
	while(m--){
		ri l=qr(),r=qr(),x=qr(),y=qr();
		ri pos=lower_bound(a+1,a+k+1,node{x})-a;
		puts(query(rt[pos],1,n,l,r)>y?"no":"yes"),fflush(stdout);
	}
	return 0;
}