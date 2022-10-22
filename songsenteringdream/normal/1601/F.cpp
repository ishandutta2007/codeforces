#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD1=998244353,MOD2=1e9+7;
inline int fix(long long x){if((x%=MOD1)<0) x+=MOD1;return x;}
int cnt,ans,s[7];long long n,tot;vector<int> vec[7];
void Dfs(int d,int nw){
	vec[d].push_back(fix((cnt++)-nw));
	if(d>5) return;
	for(int i=0;i<10;++i) Dfs(d+1,nw*10+i);
}
void dfs(long long nw){
	if(nw>n) return;
	if(nw*10000000>n&&nw*1000000+999999<=n){
		for(int i=0,pw=1,j;i<7;++i,pw*=10)
			j=fix(tot+1-nw*pw),ans=(ans+j*1ll*vec[i].size()+s[i]+MOD2-(vec[i].end()-lower_bound(vec[i].begin(),vec[i].end(),MOD1-j))*1ll*MOD1%MOD2)%MOD2;
		tot+=cnt;
		return;
	}
	ans=(ans+fix((++tot)-nw))%MOD2;
	for(int i=0;i<10;++i) dfs(nw*10+i);
}
int main(){
	scanf("%lld",&n);
	Dfs(0,0);
	for(int i=0,j;i<7;++i) for(sort(vec[i].begin(),vec[i].end()),j=vec[i].size();j--;) s[i]=(s[i]+vec[i][j])%MOD2;
	for(int i=1;i<10;++i) dfs(i);
	printf("%d",ans);
	return 0;
}