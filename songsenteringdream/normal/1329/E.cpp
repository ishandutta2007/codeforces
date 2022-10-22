#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int o=4e5+10;const long long inf=1e18;
int T,m,cnt;long long n,k,ans,p[o],L0,R0,t1,t2;pair<long long,long long> lim[o];
inline bool chk1(long long v){
	long long res=0;
	for(int i=1;i<=m;++i) res+=p[i]/v-1;
	for(int i=1;i<=m;++i) if(p[i]<v) return false;
	return res>=k;
}
inline bool chk2(long long v){
	long long res=0;
	for(int i=1;i<=m;++i) res+=(p[i]+v-1)/v-1;
	return res<=k;
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),cnt=0){
		scanf("%lld%d%lld",&n,&m,&k);p[++m]=n;ans=inf;
		for(int i=1;i<m;++i) scanf("%lld",&p[i]);
		for(int i=m;i;--i) p[i]-=p[i-1];
		for(long long l=L0=1,r=n,md;l<r;L0=l) if(chk1(md=(l+r>>1)+1)) l=md;else r=md-1;
		for(long long l=1,r=R0=n,md;l<r;R0=r) if(chk2(md=l+r>>1)) r=md;else l=md+1;
		if(L0>=R0){ans=0;continue;}
		for(int i=1;i<=m;++i) if((t1=p[i]/L0)<(t2=(p[i]+R0-1)/R0)) lim[++cnt]=make_pair(p[i]/t2,(p[i]+t1-1)/t1);
		lim[++cnt]=make_pair(L0,inf);
		sort(lim+1,lim+cnt+1);
		for(int i=1;i<=cnt;R0=max(R0,lim[i++].second)) ans=min(ans,R0-lim[i].first);
	}
	return 0;
}