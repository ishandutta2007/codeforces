#include <bits/stdc++.h>
using namespace std;
const int N=3000+10;
typedef long long LL;
const LL MOD=998244353;

char s[N],t[N];
int n,m;
LL g[N][N];
LL solve1(){
	// g[i][j] s.[1,i], match [j,min(j+i-1,m)]
	for(int i=1;i<=m;i++){
		if(t[i]==s[1]){
			g[1][i]=1;
		}
	}
	g[1][m+1]=1;
	LL ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			if(j==1 && j+i-1>=m) {
				(ans+=g[i][j])%=MOD;
			}
			if(g[i][j]){
				//printf("g[%d][%d]=%lld\n", i,j,g[i][j]);
				int lef=j, rig=min(j+i-1,m);
				-- lef, ++ rig;
				if (lef>=1 && lef<=m) {
					if(s[i+1]==t[lef])
					(g[i+1][lef] += g[i][j]) %= MOD;
				} 
				if(j==m+1){
					(g[i+1][j] += g[i][j]) %= MOD;
				}
				if (rig>=1 && rig<=m) {
					if(s[i+1]==t[rig])
						(g[i+1][j] += g[i][j]) %= MOD;
				}
				if (rig == m+1) {
					(g[i+1][j] += g[i][j]) %= MOD;
				}
			}
		}
	}
	//printf("solve1 ans = %lld\n", ans);
	return ans;
}
LL brt(){
	int ans=0;
	for(int len=0;len<=n;len++){
		for(int i=0;i<1<<len;i++){
			string res="";
			for(int j=0;j<len;j++){
				if(i>>j&1){
					res=res+s[j+1];
				}else{
					res=s[j+1]+res;
				}
				if(j==len-1) {
					bool fg=1;
					for(int k=0;k<m;k++) if(res[k]!=t[k+1]) fg=0;
					if(fg) {
						cout<<res<<endl;
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1); m=strlen(t+1);
	//brt();
	LL ans=solve1()%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans*2%MOD<<endl;

}