#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int o=3e5+10;const long long inf=1e18;
int T,n,a[o],cnt,lg[o];long long ans,s[o][2],v;map<long long,int> mp;vector<int> vec[o];
struct ST{
	long long st[o][20];
	inline long long query(int l,int r){int t=lg[r-l+1];return min(st[l][t],st[r-(1<<t)+1][t]);}
	inline void init(){
		for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
			st[j][i]=min(st[j][i-1],(j+(1<<(i-1))<=n?st[j+(1<<(i-1))][i-1]:inf));
	}
}z[2];
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=cnt=0,mp.clear()){
		scanf("%d",&n);lg[0]=-1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),lg[i]=lg[i>>1]+1;
		for(int i=1;i<=n;++i) s[i][0]=s[i-1][0],s[i][1]=s[i-1][1],s[i][i&1]+=a[i];
		for(int i=1;i<=n;++i) z[i&1].st[i][0]=s[i][i&1]-s[i-1][!(i&1)],z[!(i&1)].st[i][0]=inf;
		z[0].init();z[1].init();
		for(int i=1;i<=n;vec[mp[v]].push_back(i++)) if(!mp[v=s[i][0]-s[i][1]]) vec[mp[v]=++cnt].clear();
		for(int i=1,j,k,l,r,md;i<=n;++i) if(j=mp[s[i-1][0]-s[i-1][1]]){
			for(l=i,r=n;l<r;)
				if(z[0].query(i,md=(l+r>>1)+1)-s[i-1][0]+s[i-1][1]>=0&&z[1].query(i,md)-s[i-1][1]+s[i-1][0]>=0) l=md;
				else r=md-1;
			for(k=l,l=-1,r=vec[j].size()-1;l<r;) if(vec[j][md=(l+r>>1)+1]<=k) l=md;else r=md-1;
			ans+=l+1;
			for(l=-1,r=vec[j].size()-1;l<r;) if(vec[j][md=(l+r>>1)+1]<i) l=md;else r=md-1;
			ans-=l+1;
		}
	}
	return 0;
}