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
#define MAXN 310000
int ans[MAXN];
vector<int>seg[1100000];
vector<pii>que[1100000];
int tmp[MAXN];int n,m;
int cnt[1010000];
inline void add(int x){for(;x<=1000000;x+=lowbit(x))cnt[x]++;}
inline int ask(int x){int res=0;for(;x;x-=lowbit(x))res+=cnt[x];return res;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int l,r;scanf("%d%d",&l,&r);
		seg[r].pb(l);
	}
	rep(i,1,m){
		int cnt;scanf("%d",&cnt);
		rep(j,1,cnt)scanf("%d",&tmp[j]);
		sort(tmp+1,tmp+1+cnt);
		tmp[0]=0;
		rep(j,1,cnt)que[tmp[j]].pb((pii){i,tmp[j-1]+1});
	}
	per(i,1000000,1){
		for(int j=0;j<seg[i].size();j++)
		add(seg[i][j]);
		for(int j=0;j<que[i].size();j++)
		ans[que[i][j].fi]+=ask(i)-ask(que[i][j].se-1);
	}
	rep(i,1,m)printf("%d\n",ans[i]);
	return 0;
}