#include<iostream>
#include<map>
using namespace std;
inline int Max(int a,int b){return a>b?a:b;}
const int o=100;
int n,m,k,q[o],p[o],u[o],v[o];bool g[o][o],vis[o][o];long long ans,c[o];map<long long,bool> mp,usd;
inline bool chk1(){
	for(int i=0;i<(n>>1);++i) u[i]=v[i]=0;
	for(int i=1;i<=n;++i) if(u[p[i]-1]) v[p[i]-1]=i;else u[p[i]-1]=i;
	for(int i=0;i<(1<<(n>>1));++i) for(int j=0;j<(n>>1);++j) vis[i][j]=0;
	for(int i=0;i<(n>>1);++i) if(g[u[i]][v[i]]) vis[1<<i][i]=1;
	for(int i=1;i<(1<<(n>>1));++i) for(int j=0;j<(n>>1);++j) if(vis[i][j])
		for(int $=0;$<(n>>1);++$) if(!(i&(1<<$)))
			vis[i|(1<<$)][$]|=((g[u[j]][u[$]]&&g[v[j]][v[$]])||(g[u[j]][v[$]]&&g[v[j]][u[$]]));
	for(int i=0;i<(n>>1);++i) if(vis[(1<<(n>>1))-1][i]) return true;
	return false;
}
bool chk2(){
	long long hsh=0;int mxc=0;
	for(int i=1;i<=n;++i) hsh=hsh*7+p[i],mxc=Max(mxc,p[i]);
	if(mp.count(hsh)) return mp[hsh];
	if(mxc==(n>>1)) return mp[hsh]=chk1();
	int cnt[7];
	for(int i=1;i<=(n>>1);++i) cnt[i]=0;
	for(int i=1;i<=n;++i) ++cnt[p[i]];
	for(int i=1;i<=n;++i) if(cnt[p[i]]>2){
		for(int j=i+1,$=p[i];j<=n;++j)
			if($==p[j]){
				p[i]=p[j]=mxc+1;
				if(chk2()){p[i]=p[j]=$;return mp[hsh]=true;}
				p[i]=p[j]=$;
			}
		break;
	}
	return mp[hsh]=false;
}
void dfs(int col){
	int beg=1;
	for(;q[beg];++beg);
	if(beg>n){
		long long hsh=0;
		for(int i=1;i<=n;++i) hsh=hsh*7+(p[i]=q[i]);
		if(usd[hsh]) return;usd[hsh]=1;
		if(chk2()) ans+=c[col-1];
		return;
	}
	for(int i=1;i<=col;++i) for(int j=beg+1;j<=n;++j)
		if(!q[j]) q[beg]=q[j]=i,dfs(Max(col,i+1)),q[beg]=q[j]=0;
}
int main(){
	cin>>n>>m>>k;
	for(int i=c[0]=1;i<=k;++i) c[i]=c[i-1]*(k-i+1);
	for(int i=1,$,_;i<=m;++i) cin>>$>>_,g[$][_]=g[_][$]=1;
	dfs(1);
	cout<<ans;
	return 0;
}