#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,q,mod;
int a[300010],b[300010],fib[300010];
int c[300010];
int mx[1200010];
void pushup(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		mx[p]=(c[l]+mod)%mod;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p);
}
void add(int p,int l,int r,int pos,int k){
	if(pos<l||pos>r) return ;
	if(l==r){
		mx[p]=((1ll*mx[p]+k)%mod+mod)%mod;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) add(p<<1,l,mid,pos,k);
	else add(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
int main(){
	n=read(),q=read(),mod=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read(),c[i]=(b[i]-a[i]+mod)%mod;
	fib[1]=fib[2]=1;
	for(int i=3;i<=n;++i) fib[i]=(fib[i-1]+fib[i-2])%mod;
	for(int i=n;i>1;--i) c[i]=(1ll*c[i]-c[i-1]-c[i-2]+mod+mod)%mod;
	build(1,1,n);
	for(int i=1;i<=q;++i){
		char c=getchar();
		while(c!='A'&&c!='B') c=getchar();
		int l=read(),r=read();
		int x=1;
		if(c=='A') x=mod-1;
		add(1,1,n,l,x);
		add(1,1,n,r+1,1ll*x*(1ll*mod-fib[r-l+1]+mod-fib[r-l])%mod);
		add(1,1,n,r+2,1ll*x*(mod-fib[r-l+1])%mod);
		if(mx[1]) printf("NO\n");else printf("YES\n");
	}
}