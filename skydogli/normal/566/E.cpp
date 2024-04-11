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
#define MN 1005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m;
bool app[MN],use[MN],vis[MN][MN];
bitset<1005>G[MN],E[MN],tmp,all;
vector<pii >ans;
int F[MN],pos[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
signed main(){
	n=read();
	bool flag=1;
	for(int i=1;i<=n;++i)F[i]=i;
	for(int i=1;i<=n;++i){
		int k=read();
		flag&=(k==n);
		for(int j=1;j<=k;++j)G[i][read()]=1;
	}
	if(flag){
		for(int i=2;i<=n;++i) printf("1 %lld\n",i);
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			tmp=G[i]&G[j];
			if(tmp.count()==2){
				int x=tmp._Find_first();
				int nxt=tmp._Find_next(x);
				if(vis[x][nxt])continue;
				vis[x][nxt]=1;
				ans.pb(mp(x,nxt));
				use[x]=1;use[nxt]=1;
				all[x]=1;all[nxt]=1;
				E[x][nxt]=1;E[nxt][x]=1;
		//		cerr<<"edg: "<<x<<" "<<nxt<<endl;
			}
			if(Find(i)==Find(j))F[Find(i)]=Find(j);
		}
	for(int i=1;i<=n;++i)E[i][i]=1;
	for(int i=1;i<=n;++i){
		if(!use[i])
			for(int j=1;j<=n;++j)
				if(G[j][i]&&(!pos[i]||G[j].count()<G[pos[i]].count()))
					pos[i]=j;
	}
	//	cerr<<"ans: "<<ans.size()<<endl;
	if(ans.size()==1){
		int A=0;
		for(int i=1;i<=n;++i){
			if(!use[i]){
				A=pos[i];break;
			}
		}
		for(int i=1;i<=n;++i)
			if(!use[i])ans.pb(mp(i,pos[i]==A?ans[0].x:ans[0].y));

	}
	else 	
		for(int i=1;i<=n;++i){
			if(!use[i]){
//				cerr<<i<<": "<<pos[i]<<endl;
				for(int j=1;j<=n;++j){
					if(use[j]&&(G[pos[i]]&all)==E[j]){
//						cerr<<"ok: "<<j<<" "<<endl;
						ans.pb(mp(i,j));
						break;
					}
				}
			}
		}
	//	cerr<<"ans: "<<ans.size()<<endl;
	assert(ans.size()==n-1);
	for(int i=0;i<ans.size();++i)
		printf("%lld %lld\n",ans[i].x,ans[i].y);
	return 0;
}