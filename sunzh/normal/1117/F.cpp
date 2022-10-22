#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,p;
char str[100010];
bool g[17][17];
bool c[17][17][1<<17];
vector<int>vec[17];
bool dp[1<<17];
bool check(int S){
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			if(g[i][j]) continue ;
			if(!c[i][j][S]) continue ;
			if(S&(1<<i)) continue ;
			if(S&(1<<j)) continue ;
			return 0;
		}
	}
	return 1;
}
int main(){
	n=read(),p=read();
	scanf("%s",str+1);
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j) g[i][j]=read();
	}
	for(int i=1;i<=n;++i) vec[str[i]-'a'].pb(i);
//	for(int i=0;i<p;++i){
//		printf("i:%d,%d\n",i,vec[i].size());
//		for(int j:vec[i]) printf("%d ",j);printf("\n");
//	}
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			if(g[i][j]) continue ;
			if(i==j){
				for(int k=1;k<vec[i].size();++k){
					int S=0;
					for(int l=vec[i][k-1]+1;l<vec[i][k];++l) S|=(1<<(str[l]-'a'));
					c[i][j][S]=1;
				}
				for(int k=0;k<(1<<p);++k) if(c[i][j][k]) for(int l=0;l<p;++l) if(!(k&(1<<l))) c[i][j][k|(1<<l)]=1;
				continue ;
			}
			int p1=-1,p2=-1;
//			printf("i:%d,j:%d\n",i,j);
			vector<PII>pos;
			for(int k:vec[i]) pos.pb(mp(k,0));
			for(int k:vec[j]) pos.pb(mp(k,1));
			sort(pos.begin(),pos.end());
			for(int k=1;k<pos.size();++k){
				if(pos[k-1].se!=pos[k].se){
					int S=0;
					for(int l=pos[k-1].fi+1;l<pos[k].fi;++l) S|=(1<<(str[l]-'a'));
//					printf("S:%d\n",S);
					c[i][j][S]=1;
				}
			}
			for(int k=0;k<(1<<p);++k) if(c[i][j][k]) for(int l=0;l<p;++l) if(!(k&(1<<l))) c[i][j][k|(1<<l)]=1;
//			printf("i:%d,j:%d\n",i,j);
		}
	}
	dp[0]=1;
	for(int i=0;i<(1<<p);++i){
		if(dp[i]){
			if(!check(i)){
				dp[i]=0;continue ;
			}
			for(int j=0;j<p;++j){
				if(!(i&(1<<j))){
					int S=i|(1<<j);
					dp[S]=1;
				}
			}
		}
	}
	int ans=n;
	for(int i=0;i<(1<<p);++i){
		if(dp[i]){
			int res=n;
			for(int j=0;j<p;++j){
				if(i&(1<<j)) res-=vec[j].size();
			}
			ans=min(ans,res);
		}
	}
	printf("%d\n",ans);
}