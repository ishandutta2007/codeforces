#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int typ;
int n;
int h[500010];
int ans[500010];
set<int>st;
int Id[500010];
bool cmp(int x,int y){
	return h[x]>h[y]; 
}
bool b[500010];
int Ans;
struct node{
	int vl,vr,l,r,ans;
	bool full;
	node(){
		vl=vr=l=r=full=0;
	}
	void init(int x){
		vl=vr=x;l=r=ans=full=1;
	}
}tre[2000010];
node pushup(node ls,node rs){
	node u;
	u.vl=ls.vl,u.vr=rs.vr;
	u.ans=max(ls.ans,rs.ans);
	u.l=ls.l,u.r=rs.r;
	u.full=0;
	if(ls.vr^rs.vl){
		u.ans=max(u.ans,ls.r+rs.l);
		u.full=(ls.full&rs.full);
		if(ls.full) u.l=ls.l+rs.l;
		if(rs.full) u.r=rs.r+ls.r;
	}
	return u;
}
void build(int p,int l,int r){
	if(l==r){
		tre[p].init(0);
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	tre[p]=pushup(tre[p<<1],tre[p<<1|1]);
} 
void modify(int p,int l,int r,int pos){
	if(l==r){
		tre[p].init(1);
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(p<<1,l,mid,pos);
	else modify(p<<1|1,mid+1,r,pos);
	tre[p]=pushup(tre[p<<1],tre[p<<1|1]);
	return ; 
}
node queryl(int p,int l,int r,int pos){
	if(l==r) return tre[p];
	int mid=l+r>>1;
	if(pos<=mid) return queryl(p<<1,l,mid,pos);
	node u=queryl(p<<1|1,mid+1,r,pos);
	return pushup(tre[p<<1],u);
}
node queryr(int p,int l,int r,int pos){
	if(l==r) return tre[p];
	int mid=l+r>>1;
	if(pos>mid) return queryr(p<<1|1,mid+1,r,pos);
	node u=queryr(p<<1,l,mid,pos);
	return pushup(u,tre[p<<1|1]);
}
void firm(int l,int r,int x){
	auto itl=st.lower_bound(l);
	if(itl==st.end()) return ;
	vector<set<int>::iterator>vit;
	while(itl!=st.end()&&(*itl)<=r){
		vit.pb(itl);ans[*itl]=x;
		++itl;
	} 
	for(auto i:vit) st.erase(i);
}
int main(){
//	typ=read();
	n=read();
	for(int i=1;i<=n;++i){
		h[i]=read();st.insert(i);Id[i]=i;
	}
	sort(Id+1,Id+n+1,cmp);
	build(1,1,n);
	for(int i=1;i<=n;++i){
		modify(1,1,n,Id[i]);b[Id[i]]=1;
		if(h[Id[i]]!=h[Id[i+1]]) Ans=max(Ans,tre[1].ans-1>>1);
		node tl=queryl(1,1,n,Id[i]);
		node tr=queryr(1,1,n,Id[i]);
		int sl=Id[i]-tl.r+1,sr=Id[i]+tr.l-1;
//		printf("%d %d\n",sl,sr);
		if(b[sl]==0){
			if(b[sr]==1){
				int len=(sr-sl+1);
//				printf("%d %d\n",sr-(len>>1)+1,sr);
				firm(sr-(len>>1)+1,sr,h[Id[i]]);
			}
		}
		else{
			if(b[sr]==0){
				int len=sr-sl+1;
				firm(sl,sl+(len>>1)-1,h[Id[i]]);
			}
			else firm(sl,sr,h[Id[i]]);
		}
		if(sl==Id[i]&&Id[i]!=1){
			node tmp=queryl(1,1,n,Id[i]-1);
			int len=tmp.r;
			firm(Id[i]-(len>>1),Id[i],h[Id[i]]);
		}
		if(sr==Id[i]&&Id[i]!=n){
			node tmp=queryr(1,1,n,Id[i]+1);
			int len=tmp.l;
			firm(Id[i],Id[i]+(len>>1),h[Id[i]]);
		}
	}
	printf("%d\n",Ans);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}