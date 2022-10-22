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
const int mod=1e9+7;
int n,q;
int a[2000010],w[2000010];
__int128 tre[2000010];
int tre1[2000010];
void upd(int x,int k){
	int T=1ll*((a[x]-x)%mod+mod)%mod*k%mod;
	while(x<=n){
		(tre1[x]+=T)%=mod;
		tre[x]+=k;x+=x&-x;
	}
}
int Qry(int x){
	int ret=0;
	while(x){
		(ret+=tre1[x])%=mod;x-=x&-x;
	}
	return ret;
}
int Query(int l,int r){
	if(l>r) return 0;
	return (Qry(r)-Qry(l-1)+mod)%mod;
}
__int128 qry(int x){
	__int128 ret=0;
	while(x){
		ret+=tre[x];x-=x&-x;
	}
	return ret;
}
__int128 query(int l,int r){
	if(l>r) return 0ll;
	return qry(r)-qry(l-1);
}
signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) w[i]=read(),upd(i,w[i]);
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		if(x<0){
			int id=-x,nw=y;
			upd(id,nw-w[id]);w[id]=nw;
		}
		else{
			int l=x,r=y;
			int res=l;--r;
			while(l<=r){
				int mid=l+r>>1;
				__int128 L=query(x,mid),R=query(mid+1,y);
				// printf("mid:%d,L:%d,R:%d\n",)
				if(L<R) res=mid+1,l=mid+1;
				else r=mid-1; 
			}
			int sl=Query(x,res),sr=Query(res+1,y);
			// for(int j=x;j<=y;++j) printf("%d ",w[j]);printf("\n");
			// printf("res:%d\n",res);
			sr=(sr-1ll*query(res+1,y)%mod*((a[res]-res)%mod+mod)%mod+mod)%mod;
			sl=(1ll*query(x,res)%mod*((a[res]-res)%mod+mod)%mod-sl+mod)%mod;
			printf("%lld\n",(1ll*sl+sr+mod)%mod);
		}
	}
}