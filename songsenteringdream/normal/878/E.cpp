#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
const int o=1e5+10,MOD=1e9+7,inf=2e9+10;
int n,q,a[o],s[o],s_[o],sm[o],v[o],len[o],fa[o],pw[o],ans[o];vector<pair<int,int> > ask[o];
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
inline void merge(int x,int y){
	if(len[x]>30||sm[x]+sm[y]*(1ll<<len[x])>=inf) sm[x]=inf;
	else sm[x]+=sm[y]<<len[x];
	v[x]=(v[x]+v[y]*1ll*pw[len[x]])%MOD;len[fa[y]=x]+=len[y];
}
inline int calc(int l,int r){return (s[l]+(MOD-s[r+1])*1ll*pw[r-l+1])%MOD;}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=pw[0]=1;i<=n;++i) pw[fa[i]=i]=pw[i-1]*2%MOD;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i;--i) s[i]=(s[i+1]*2ll+a[i]+MOD)%MOD;
	for(int i=1,l,r;i<=q;++i) scanf("%d%d",&l,&r),ask[r].push_back(make_pair(l,i));
	for(int i=1;i<=n;++i){
		for(v[i]=((sm[i]=a[i])+MOD)%MOD,len[i]=1;fr(i)>1&&sm[fr(i)]>0;merge(fr(fr(i)-1),fr(i)));
		s_[fr(i)]=(s_[fr(fr(i)-1)]+v[fr(i)])%MOD;
		for(int j=ask[i].size(),l;j--;)
			l=ask[i][j].first,ans[ask[i][j].second]=(calc(l,fr(l)+len[fr(l)]-1)+2ll*(s_[fr(i)]+MOD-s_[fr(l)]))%MOD;
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}