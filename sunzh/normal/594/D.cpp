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
int n,q;
int a[1000010];
const int mod=1e9+7;
int pre[1000010];
int ls[1000010];
vector<pair<int,int> >Q[1000010]; 
int ans[1000010];
int tre[1000010];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1; 
	}
	return res;
}
void getpre(){
	for(int i=2;i<=1e6;++i){
		if(!pre[i]) for(int j=1;j*i<=1e6;++j){
			pre[j*i]=i;
		}
	}
}
void update(int x,int k){
	while(x){
		tre[x]=1ll*tre[x]*k%mod;
		x-=x&-x;
	}
}
int query(int x){
	int res=1;
	while(x<=n){
		res=1ll*res*tre[x]%mod;
		x+=x&-x;
	}
	return res;
}
void solve(){
	getpre(); 
	for(int i=1;i<=n;++i){
		int x=a[i];
		while(x>1){
			int p=pre[x];
			int tm=0;
			while(x%p==0) x/=p,++tm;
			update(i,1ll*qpow(p,tm-1)*(p-1)%mod);update(ls[p],1ll*qpow(p-1,mod-2)*p%mod);
			ls[p]=i;
		}
		for(int j=0;j<Q[i].size();++j) ans[Q[i][j].second]=query(Q[i][j].first);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),tre[i]=1;q=read();
	for(int i=1;i<=q;++i){
		int l=read(),r=read();Q[r].push_back(make_pair(l,i));
	}
	solve();
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}