#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[200010];
int t[200010];

int res[800010];
void pushup(int p){
	res[p]=max(res[p<<1],res[p<<1|1]);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return res[p];
	int mid=l+r>>1,ans=0;
	pushup(p);
	if(mid>=L) ans=max(ans,query(p<<1,l,mid,L,R));
	if(mid<R) ans=max(ans,query(p<<1|1,mid+1,r,L,R));
	return ans; 
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		res[p]=k;
		return ;
	}
	int mid=l+r>>1;
	if(mid>=L)update(p<<1,l,mid,L,R,k);
	if(mid<R)update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int q=read();
	for(int i=1;i<=q;++i){
		int op=read();
		if(op==1){
			int p=read(),x=read();
			t[p]=i,a[p]=x;
		}
		else{
			int x=read();
			update(1,1,q,i,i,x);
		}
	}
	for(int i=1;i<=n;++i){
		a[i]=max(a[i],query(1,1,q,t[i]+1,q));
	}
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}