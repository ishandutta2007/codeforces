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
const int N=510000;
int val[N*4];
int n,m;int a[N];
vector<pii>ask[N];int ans[N];
map<int,int>np;
inline void modify(int me,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		if(v<val[me])val[me]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(me*2,l,mid,x,y,v);
	if(y>mid)modify(me*2+1,mid+1,r,x,y,v);
}
inline int go(int me,int l,int r,int x){
	if(l==r)return val[me];
	int mid=(l+r)>>1;
	int ans=0;
	if(x<=mid)ans=go(me*2,l,mid,x);
	else ans=go(me*2+1,mid+1,r,x);
	if(val[me]<ans)ans=val[me];
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	memset(val,63,sizeof val);
	rep(i,1,m){
		int l,r;scanf("%d%d",&l,&r);
		ask[l].pb(pii(i,r));
	}
	per(i,n,1){
		if(np.find(a[i])!=np.end()){modify(1,1,n,np[a[i]],n,np[a[i]]-i);}
		np[a[i]]=i;
		rep(j,0,ask[i].size()-1)ans[ask[i][j].fi]=go(1,1,n,ask[i][j].se);
	}
	rep(i,1,m){
		if(ans[i]>1000000000)printf("-1\n");else
		printf("%d\n",ans[i]);
	}
	return 0;
}