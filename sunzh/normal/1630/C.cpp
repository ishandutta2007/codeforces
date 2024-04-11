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
int n;
int a[200010];
int lf[200010],rg[200010];
int R[200010];
bool vis[200010];
int s[200010];
int mx[800010],sum[800010];
void build(int p,int l,int r){
	if(l==r){
		if(R[l]) mx[p]=R[l];
		sum[p]=vis[l];
		return ;
	}
	int mid=l+r>>1;build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);sum[p]=sum[p<<1]+sum[p<<1|1];
}
int nwr=0;
int querys(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return sum[p];
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res+=querys(p<<1,l,mid,L,R);
	if(R>mid) res+=querys(p<<1|1,mid+1,r,L,R);
	return res;
}
int qrymx(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res=max(res,qrymx(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,qrymx(p<<1|1,mid+1,r,L,R));
	return res;
}
int ans;
void chk(int l,int r){
	if(r<=nwr) return ;
	nwr=r;
	int s=querys(1,1,n,l+1,r-1);
	int mx=qrymx(1,1,n,l+1,r-1);
	// printf("l:%d,r:%d,s:%d,mx:%d\n",l,r,s,mx);
	if(mx>r){
		ans+=s;chk(r,mx);
	}
	else ans+=s;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) lf[i]=n,rg[i]=0;
	for(int i=1;i<=n;++i) a[i]=read(),lf[a[i]]=min(lf[a[i]],i),rg[a[i]]=i;
	for(int i=1;i<=n;++i) if(lf[i]<=rg[i]){
		vis[lf[i]]=vis[rg[i]]=1;
		s[lf[i]]++;s[rg[i]+1]--;R[lf[i]]=rg[i];
	}
	build(1,1,n);
	for(int i=1;i<=n;++i) s[i]+=s[i-1];
	ans=0;
	for(int i=1;i<=n;++i) if(!vis[i]) ans+=(s[i]>0);
	nwr=0;
	// printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		if(R[i]){
			chk(i,R[i]);
		}
	}
	printf("%d\n",ans);
}