#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=18;
vector<int> a[N];
LL sa[N];
pii pos[N*5000];
LL sum=0;
map<LL,int> f;
int idx[N][5000];
int k;
int n;
bool vis[N*5000];
int np(int i){
	LL aft=sa[pos[i].fi]-a[pos[i].fi][pos[i].se];
	if(!f[sum/n-aft])return 0;
	int v=f[sum/n-aft];
	if(v==i)return 0;
	return v;
}
int can[1<<15];
int g[1<<15];
int ac[N],ap[N];
void gkd(int S){
	if(can[S]==0){
		int idx=0;
		rep(i,0,n-1)if(S&(1<<i))idx=i+1;
		assert(idx);
		ac[idx]=a[idx][0];
		ap[idx]=idx;
		return;
	}
	int x=can[S];
	int now=x;
	while(1){
		int y=np(now);
		ap[pos[y].fi]=pos[now].fi;
		ac[pos[y].fi]=a[pos[y].fi][pos[y].se];
		now=y;
		if(now==x)break;
	}
}
bool hr[N*5000];

int q[N*5000];
int du[N*5000];

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int t;scanf("%d",&t);
		while(t--){
			int x;scanf("%d",&x);a[i].pb(x);
			sa[i]+=x;
			sum+=x;
		}
	}
	if(sum%n!=0){
		puts("No");
		return 0;
	}
	rep(i,1,n)rep(j,0,a[i].size()-1){
		idx[i][j]=++k;
		pos[k]=pii(i,j);
		f[a[i][j]]=k;
	}

	rep(i,1,k)du[np(i)]++;
	rep(i,1,k)if(!du[i])q[++q[0]]=i;
	rep(i,1,q[0]){
		int x=q[i];
		int y=np(x);
		if(!y)continue;
		du[y]--;
		if(!du[y])q[++q[0]]=y;
	}
	rep(i,1,q[0])vis[q[i]]=1;

	rep(i,1,k)if(!vis[i]){
		int S=0;
		int now=i;
		while(1){
			if((1<<(pos[now].fi-1))&S){
				S=-1;
				break;
			}
			S|=(1<<(pos[now].fi-1));
			vis[now]=1;
			now=np(now);
			if(!now){
				S=-1;
				break;
			}
			if(now==i)break;
		}
		if(S!=-1)can[S]=i;
	}


	rep(S,1,(1<<n)-1){
		if(can[S])g[S]=S;
		else{
			rep(i,1,n)if(sa[i]==sum/n)if(S&(1<<(i-1))){
				can[(1<<(i-1))]=0;
				if(g[S^(1<<(i-1))]||(S==(1<<(i-1))))g[S]=(1<<(i-1));
			}
			for(int T=S;T;T=(T-1)&S)if(g[S^T]&&can[T]){
				g[S]=T;
				break;
			}
		}
	}
	if(!g[(1<<n)-1]){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int S=(1<<n)-1;
	while(S){
		gkd(g[S]);
		S^=g[S];
	}
	rep(i,1,n)printf("%d %d\n",ac[i],ap[i]);
	return 0;
}