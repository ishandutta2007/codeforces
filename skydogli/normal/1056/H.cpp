#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 300005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
int T,n,m;
int k[MN],vis[MN];
vector<int>p[MN];
vector<pii >e[MN];
pii fk[MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;++i)e[i].clear();
		int S=0;
		for(int i=1;i<=m;++i){
			p[i].resize(k[i]=read());
			S+=k[i];
			for(int j=0;j<p[i].size();++j)p[i][j]=read();
		}
		int blk=sqrt(S),ok=0;
		for(int i=1;i<=m&&!ok;++i){
			if(k[i]>=blk){
				for(int j=1;j<=n;++j)vis[j]=-1;
				for(int j=0;j<p[i].size();++j)vis[p[i][j]]=j;
				for(int j=1;j<=m&&!ok;++j){
					if(j<=i&&k[j]>=blk)continue;
					int mx=vis[p[j].back()];
					for(int o=(int)p[j].size()-2;o>=0;--o){
						if(vis[p[j][o]]!=-1&&vis[p[j][o]]<=mx&&vis[p[j][o]]!=p[i].size()-1){
							if(p[j][o+1]!=p[i][vis[p[j][o]]+1]){
								ok=1;
								break;
							}
						}
						mx=max(mx,vis[p[j][o]]);
					}
				}
			}
			else{
				for(int j=0;j<p[i].size();++j)
					for(int k=j+1;k<p[i].size();++k){
						e[p[i][j]].pb(mp(p[i][k],p[i][j+1]));
					}
			}
		}
		if(!ok){
			for(int i=1;i<=n;++i)fk[i]=mp(0,0);
			for(int i=1;i<=n&&!ok;++i){
				for(int j=0;j<e[i].size();++j){
					int v=e[i][j].x,w=e[i][j].y;
					if(fk[v].x!=i)fk[v]=mp(i,w);
					else if(fk[v].y!=w){ok=1;break;}
				}
			}
		}
		puts(ok?"Human":"Robot");
	}
	return 0;
}