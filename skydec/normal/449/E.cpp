#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
const int N=1100000;
int f[N],g[N],h[N],q[N],phi[N],n,pr[N],tot;bool is[N];
inline void init(){
	phi[1]=1;
	rep(i,2,n){
		if(!is[i]){pr[++tot]=i;phi[i]=i-1;}
		rep(j,1,tot){
			if(pr[j]*1ll*i>n)break;
			is[pr[j]*i]=1;
			if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}
			else phi[i*pr[j]]=phi[i]*(pr[j]-1);
		}
	}
	rep(i,1,n)rep(j,1,n/i)q[i*j]=(q[i*j]+i*1ll*phi[j])%P;
	rep(i,1,n){
		f[i]=q[i];f[i]=(f[i]-i*1ll*i)%P;
		int x=i;int y=i+1;int z=2ll*i+1;
		if(x%2==0)x/=2ll;else if(y%2==0)y/=2ll;else z/=2ll;
		if(x%3==0)x/=3ll;else if(y%3==0)y/=3ll;else z/=3ll;
		f[i]=(f[i]+(x*1ll*y%P)*1ll*z)%P;
		int bo=((i+1)*1ll*i/2ll)%P;bo=bo*1ll*i%P;
		f[i]=(f[i]-bo)%P;
		f[i]=f[i]*2ll%P;
		bo=i*1ll*i%P;bo=bo*1ll*i%P;
		f[i]=(f[i]+bo)%P;
		g[i]=i*1ll*f[i]%P;
		h[i]=i*1ll*g[i]%P;
	}
	rep(i,1,n){
		f[i]=(f[i]+f[i-1])%P;
		g[i]=(g[i]+g[i-1])%P;
		h[i]=(h[i]+h[i-1])%P;
	}
}
int main(){
	n=1000000;
	init();
	int t;scanf("%d",&t);
	while(t--){
		int x,y;scanf("%d%d",&x,&y);
		int tt=min(x,y);
		int ans=0;
		ans=(ans+(f[tt]*1ll*(x+1)%P)*1ll*(y+1)%P)%P;
		ans=(ans+h[tt])%P;
		ans=(ans-(2ll+x+y)*1ll*g[tt])%P;
		if(ans<0)ans+=P;
		printf("%d\n",ans);
	}
	return 0;
}