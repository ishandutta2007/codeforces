#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int T;
int n;
int fa[200010];
int a[200010];
vector<int>vec[200010],st[200010];
int f[200010];
int dep[200010];
int mxd;
void dfs(int x){
	mxd=max(mxd,dep[x]);st[dep[x]].pb(x);
	for(int v:vec[x]){
		dep[v]=dep[x]+1;
		dfs(v);
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		mxd=0;
		for(int i=1;i<=n;++i) fa[i]=a[i]=0,vec[i].clear(),st[i].clear();
		for(int i=2;i<=n;++i)fa[i]=read(),vec[fa[i]].pb(i);
		for(int i=2;i<=n;++i) a[i]=read();
		dfs(1);
		int mx=0,nx=0;
		int lmx=0,lnx=0;
		int ans=0;
		int mx1,mx2;mx1=mx2=-0x7f7f7f7f;
		for(int v:vec[1]){
			mx1=max(mx1,-a[v]);mx2=max(mx2,a[v]);
		}
//		printf("%d %d\n",mx1,mx2);
		for(int i=1;i<=mxd;++i){
			int Mx,Mn;Mx=-0x3f3f3f3f,Mn=0x3f3f3f3f;
			for(int j:st[i]){
				Mx=max(a[j],Mx);
				Mn=min(a[j],Mn);
			}
			for(int j:st[i]){
				f[j]=max(f[fa[j]]+max(Mx-a[j],a[j]-Mn),max(mx1+a[j],mx2-a[j]));
//				printf("f[%d]=%d\n",j,f[j]);
				if(i==mxd) ans=max(ans,f[j]);
			}
			mx1=mx2=-0x7f7f7f7f;
			for(int j:st[i]){
				for(int k:vec[j]){
					mx1=max(mx1,f[j]-a[k]);
					mx2=max(mx2,f[j]+a[k]);
				}
			}
//			printf("mx1:%d,mx2:%d\n",mx1,mx2);
		}
		printf("%lld\n",ans);
	}
}