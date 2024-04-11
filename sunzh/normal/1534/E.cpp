#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,k;
int dis[510];
PII pr[510];bool vis[510];
bool tmp[510];
int main(){
	n=read(),k=read();
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	queue<PII>Q;
	Q.push(mp(0,0));
	while(!Q.empty()){
		PII now=Q.front();Q.pop();
		if(vis[now.se]) continue ;vis[now.se]=1;
		for(int i=0;i<=k&&i<=now.se;++i){
			if(now.se+k-i<=n){
				int to=now.se-i+k-i;
				if(dis[to]>dis[now.se]+1){
					dis[to]=dis[now.se]+1;pr[to]=mp(i,now.se);Q.push(mp(dis[to],to));
				}
			}
		}
	}
	if(dis[n]>n){
		printf("-1\n");return 0;
	}
	vector<int>T;
	int x=n;
	while(x){
		T.pb(pr[x].fi);x=pr[x].se;
	}
	reverse(T.begin(),T.end());
	int ans=0;
	// vector<int>nw;
	for(int p:T){
		printf("? ");
		int cnt1=0,cnt2=0;
		for(int j=1;j<=n;++j){
			if(tmp[j]&&cnt1<p){
				printf("%d ",j);++cnt1;tmp[j]^=1;
			}
			else if(tmp[j]==0&&cnt2<k-p){
				printf("%d ",j);++cnt2;tmp[j]^=1;
			}
		}
		printf("\n");fflush(stdout);
		ans^=read();
	}
	printf("! %d\n",ans);
}