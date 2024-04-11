#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int P=1000000007;
const int N=210000;
int head[N],np[N<<1],p[N<<1],tot;LL w[N<<1];
int n,m;
bool vis[N];
int q[N];
int fa[N];
LL xx[N];
int ans=0;
LL ji[65];
void add(LL x){
	per(i,60,0)if(x&(1ll<<i)){
		if(ji[i]){
			x^=ji[i];
		}
		else{
			ji[i]=x;
			break;
		}
	}
}
void work(int st){
	q[q[0]=1]=st;
	vis[st]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(!vis[p[u]]){
			vis[p[u]]=1;fa[p[u]]=x;xx[p[u]]=xx[x]^w[u];
			q[++q[0]]=p[u];
		}
	}
	memset(ji,0,sizeof ji);
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if((xx[p[u]]^xx[x]^w[u])!=0){
			LL gt=(xx[p[u]]^xx[x]^w[u]);
			add(gt);
		}
	}
	rep(i,0,60){
		int w0,w1;
		w0=w1=0;
		rep(j,1,q[0])if(xx[q[j]]&(1ll<<i))w1++;
		else w0++;
		
		int b0,b1;b0=b1=0;
		rep(j,0,60)if(ji[j])if(ji[j]&(1ll<<i))b1++;else b0++;
		
		//1:
		int ret=w1*1ll*w0%P;
		ret=ret*1ll*((1ll<<b0)%P)%P;
		if(b1)ret=ret*1ll*((1ll<<(b1-1))%P)%P;
		ans=(ans+ret*1ll*((1ll<<i)%P))%P;
		//0:
		ret=((w1*1ll*(w1-1)/2)+(w0*1ll*(w0-1)/2))%P;
		ret=ret*1ll*((1ll<<b0)%P)%P;
		if(b1)ret=ret*1ll*((1ll<<(b1-1))%P)%P;
		else ret=0;
		ans=(ans+ret*1ll*((1ll<<i)%P))%P;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y;LL c;scanf("%d%d%I64d",&x,&y,&c);
		++tot;p[tot]=y;np[tot]=head[x];head[x]=tot;w[tot]=c;
		++tot;p[tot]=x;np[tot]=head[y];head[y]=tot;w[tot]=c;
	}
	rep(i,1,n)if(!vis[i])work(i);
	printf("%d\n",ans);
	return 0;
}