#include<iostream>
#include<map>
using namespace std;
const int o=1e5+10,MOD=998244353;
int k,a,h,p1[o],p2[o],f[o],pw[o],cnt,p[o],rcd[o][40],g[o];bool flg;map<int,int> mp;
inline int fr(int x){for(;f[x];x=f[x]);return x;}
void Dfs(int nw,int ad){
	if(nw==(1<<(k-1))){
		int hsh=0;
		for(int i=1;i<=nw;++i) if(!f[i]) p[i]=2;
		for(int i=1;i<=nw;++i) hsh=(hsh+(i+ad)*1ll*pw[p[i]])%MOD;
		mp[hsh]=++cnt;
		for(int i=1;i<=nw;++i) rcd[cnt][i]=p[i];
		return;
	}
	int $=fr(p1[nw]),_=fr(p2[nw]);
	f[$]=_;p[$]=g[nw];Dfs(nw+1,ad);f[$]=0;
	f[_]=$;p[_]=g[nw];Dfs(nw+1,ad);f[_]=0;
}
void dfs(int nw,int ad){
	if(flg) return;
	if(nw==(1<<(k-1))){
		int hsh=0,$;
		for(int i=1;i<=nw;++i) if(!f[i]) p[i]=1;
		for(int i=1;i<=nw;++i) hsh=(hsh+(i+ad)*1ll*pw[p[i]])%MOD;
		if($=mp[(h+MOD-hsh)%MOD]){
			flg=1;
			if(!ad){
				for(int i=1;i<=nw;++i) cout<<p[i]<<" ";
				for(int i=1;i<=nw;++i) cout<<rcd[$][i]<<" ";
			}
			else{
				for(int i=1;i<=nw;++i) cout<<rcd[$][i]<<" ";
				for(int i=1;i<=nw;++i) cout<<p[i]<<" ";
			}
		}
		return;
	}
	int $=fr(p1[nw]),_=fr(p2[nw]);
	f[$]=_;p[$]=g[nw];dfs(nw+1,ad);f[$]=0;
	f[_]=$;p[_]=g[nw];dfs(nw+1,ad);f[_]=0;
}
int main(){
	cin>>k>>a>>h;
	for(int i=pw[0]=1;i<50;++i) pw[i]=pw[i-1]*1ll*a%MOD;
	for(int i=1,$=(1<<k-1)+1;i<(1<<k-1);i*=2,$=($+1>>1))
		for(int j=1;j<(1<<k-1);j+=i*2) p1[++cnt]=j,p2[cnt]=i+j,g[cnt]=$;
	Dfs(1,cnt=0);dfs(1,1<<k-1);
	if(flg) return 0;
	cnt=0;mp.clear();
	Dfs(1,1<<k-1);dfs(1,0);
	if(!flg) cout<<-1;
	return 0;
}