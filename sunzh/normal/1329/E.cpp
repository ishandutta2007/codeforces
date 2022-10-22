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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m,k;
int p[400010];
int det[400010];
int L,R,l,r;
bool check1(int x){
	int sum=0;
	for(int i=1;i<=m;++i) sum+=(det[i]/x-1);
	return sum>=k;
}
bool check2(int x){
	int sum=0;
	for(int i=1;i<=m;++i) sum+=(det[i]/x+(det[i]%x!=0)-1);
	return sum<=k;
}
PII xz[400010];int tot;
signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;++i) p[i]=read();
		p[++m]=n;
		for(int i=1;i<=m;++i) det[i]=p[i]-p[i-1];
		L=0,R=1e15,l=1,r=1e15;
		while(l<=r){
			int mid=l+r>>1;
			if(check1(mid)) l=mid+1,L=mid;else r=mid-1;
		}
		l=1,r=1e15;
		while(l<=r){
			int mid=l+r>>1;
			if(check2(mid)) r=mid-1,R=mid;else l=mid+1;
		}
		int ans=1e18;tot=0;xz[++tot]=mp(L,1e18);xz[++tot]=mp(-1e18,R);
		for(int i=1;i<=m;++i){
			int nr=det[i]/L,nl=det[i]/R+(det[i]%R!=0);
			if(nr>=nl) continue ;
			xz[++tot]=mp(nl?det[i]/nl:1e18,nr?(det[i]+nr-1)/nr:1e18);
		}
		sort(xz+1,xz+tot+1);
		int mx=0;
		for(int i=1;i<tot;++i) mx=max(mx,xz[i].se),ans=min(ans,mx-xz[i+1].fi);
		printf("%lld\n",max(0ll,ans));
	}
}