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
int T;
int n;
int a[200010];
vector<int>t[200010];
int to[200010];
int sum[800010],tag[800010];
int tre[200010];
void upd(int x,int k){
	while(x<=n){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int res=0;
	while(x){
		res+=tre[x];x-=x&-x;
	}
	return res;
}
void build(int p,int l,int r){
	if(l==r) sum[p]=-0x3f3f3f3f;
	if(l==r) return ;
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void pushdown(int p){
	if(tag[p]){
		sum[p<<1]+=tag[p];sum[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];tag[p]=0;return ;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		sum[p]+=k;tag[p]+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
}
void change(int p,int l,int r,int pos,int k){
	if(l==r){
		sum[p]=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) change(p<<1,l,mid,pos,k);
	else change(p<<1|1,mid+1,r,pos,k);
}
int query(int p,int l,int r,int pos){
	if(l==r){
		return sum[p];
	}
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) return query(p<<1,l,mid,pos);
	else return query(p<<1|1,mid+1,r,pos);
}
int ans[200010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) vector<int>().swap(t[i]),ans[i]=0,tre[i]=0;
		for(int i=1;i<=n;++i) a[i]=read(),t[a[i]].pb(i);
		for(int i=1;i<=n;++i){
			for(int j=0;j<t[i].size();++j) to[t[i][j]]=t[i][t[i].size()-1-j];
		}
		build(1,1,n);
		for(int i=1;i<=n;++i) if(to[i]>=i){
			ans[a[i]]+=qry(to[i]);upd(to[i],1);
			update(1,1,n,1,to[i],1);
			change(1,1,n,to[i],0);
		}
		for(int i=1;i<=n;++i) if(to[i]<=i){
			ans[a[i]]+=query(1,1,n,i);
		}
		long long Ans=0;
		for(int i=1;i<=n;++i) Ans+=ans[i];
		bool fl=0;
		for(int i=1;i<=n;++i) if(ans[i]==(Ans>>1)){
			fl=1;break ;
		}
		puts(fl?"YES":"NO");
	}
}