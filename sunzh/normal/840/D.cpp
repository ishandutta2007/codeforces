#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
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
int n,m;
int rt[300010];
struct node{
	int ls,rs,val;
}tre[8000010];
int cnt;
void build(int &p,int l,int r){
	p=++cnt;
	if(l==r) return ;
	int mid=l+r>>1;
	build(tre[p].ls,l,mid);
	build(tre[p].rs,mid+1,r);
	return ;
}
inline int modify(int ps,int l,int r,int tar){
	int now=++cnt;
	tre[now]=tre[ps];
	++tre[now].val;
	if(l==r) return now;
	int mid=l+r>>1;
	if(tar<=mid) tre[now].ls=modify(tre[ps].ls,l,mid,tar);
	else tre[now].rs=modify(tre[ps].rs,mid+1,r,tar);
	return now;
}
inline int query(int u,int v,int l,int r,int k){
	if(l==r){
		if(tre[v].val-tre[u].val>=k) return l;
		return -1;
	}
	int mid=l+r>>1;
	int res=-1;
	int x=tre[tre[v].ls].val-tre[tre[u].ls].val;
//	printf("l:%d,mid:%d,x:%d\n",l,r,x);
	if(x>=k) res=query(tre[u].ls,tre[v].ls,l,mid,k);
	if(res==-1&&tre[tre[v].rs].val-tre[tre[u].rs].val>=k) res=query(tre[u].rs,tre[v].rs,mid+1,r,k);
	return res;
}
int main(){
	n=read(),m=read();
	build(rt[0],1,n);
	for(int i=1;i<=n;++i){
		int x=read();
		rt[i]=modify(rt[i-1],1,n,x);
	}
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),k=read();
		printf("%d\n",query(rt[l-1],rt[r],1,n,(r-l+1)/k+1));
	}
	return 0;
}