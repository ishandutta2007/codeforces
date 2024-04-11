#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
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
const int N=110000;int n;LL wa,mo;LL sum[N];LL res[N];
vector<int>p[N];int num[N],dep[N];
void dfs(int x,int fa){dep[x]=dep[fa]+1;num[dep[x]]++;rep(i,0,p[x].size()-1)if(p[x][i]!=fa)dfs(p[x][i],x);}
inline LL calc(int l,int r){
	return (res[r]-res[l-1])-(sum[r]-sum[l-1])*1ll*(n-r);
}
inline bool ck(int l,int r){
	return (calc(l,r)<=mo)&&(sum[r]-sum[l-1]<=wa);
}
int main(){
	scanf("%d%I64d%I64d",&n,&wa,&mo);LL ans=0;
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);p[a].pb(b);p[b].pb(a);
	}
	dfs(1,0);
	rep(i,1,n)sum[i]=num[i]+sum[i-1];
	rep(i,1,n)res[i]=res[i-1]+num[i]*1ll*(n-i);
	rep(i,2,n){
		int l=2;int r=i;int rp=i+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(ck(mid,i))rp=mid,r=mid;
			else l=mid+1;
		}
		if(ck(l,i))rp=l;
		if(rp==i+1)ans=max(ans,wa);else
		ans=max(ans,sum[i]-sum[rp-1]+(rp!=2)*min(wa-sum[i]+sum[rp-1],(mo-calc(rp,i))/(i-(rp-1))));
	}
	printf("%I64d\n",ans);
	return 0;
}