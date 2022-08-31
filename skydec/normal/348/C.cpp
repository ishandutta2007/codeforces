#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
int size[MAXN];
vector<int> S[MAXN];
vector<pii> Jiao[MAXN];
LL Sadd[MAXN];LL add[MAXN];int n,m,q;LL bi[MAXN];
bool ct[MAXN];
LL old[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&q);rep(i,1,n)scanf("%I64d",&bi[i]);
	rep(i,1,m){
		scanf("%d",&size[i]);
		rep(j,1,size[i]){
			int v;scanf("%d",&v);old[i]+=bi[v];
			S[i].pb(v);
		}
	}
	rep(i,1,m)if(size[i]>300){
		memset(ct,0,sizeof ct);
		rep(j,1,size[i])ct[S[i][j-1]]=1;
		rep(j,1,m){
			int res=0;
			rep(k,1,size[j])if(ct[S[j][k-1]])res++;
			Jiao[j].pb((pii){i,res});
		}
	}
	while(q--){
		char opt[3];scanf("%s",opt+1);
		if(opt[1]=='?'){
			int x;scanf("%d",&x);LL res=old[x];
			if(size[x]<=300){
				rep(i,1,Jiao[x].size())res+=Sadd[Jiao[x][i-1].fi]*1ll*Jiao[x][i-1].se;
				rep(i,1,S[x].size())res+=add[S[x][i-1]]*1ll;
			}
			else{
				rep(i,1,Jiao[x].size())res+=Sadd[Jiao[x][i-1].fi]*1ll*Jiao[x][i-1].se;
			}
			printf("%I64d\n",res);
		}
		else{
			int x,v;scanf("%d%d",&x,&v);
			if(size[x]<=300){
				rep(i,1,S[x].size())add[S[x][i-1]]+=v;
				rep(i,1,Jiao[x].size())old[Jiao[x][i-1].fi]+=Jiao[x][i-1].se*1ll*v;
			}
			else{
				Sadd[x]+=v;
			}
		}
	}
	return 0;
}