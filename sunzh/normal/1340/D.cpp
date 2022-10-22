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
int n;
vector<int>vec[100010];
int Mx=0;
int nw=0;
vector<PII>ans;
void dfs(int x,int fa){
	ans.pb(mp(x,nw));
	int TM=nw;
	int dw=0;
	if(TM+vec[x].size()>=Mx){
		dw=Mx-vec[x].size();
	}
	// if(nw==Mx&&dw!=nw) nw=dw,ans.pb(mp(x,nw));
	for(int v:vec[x]){
		if(v==fa) continue ;
		if(nw==Mx) nw=dw,ans.pb(mp(x,nw));
		++nw;dfs(v,x);
		
		ans.pb(mp(x,nw));
	}
	if(x!=1&&nw!=TM-1){
		ans.pb(mp(x,TM-1));nw=TM-1;
	}++nw;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	for(int i=1;i<=n;++i) Mx=max(Mx,(int)vec[i].size());
	dfs(1,0);
	printf("%d\n",ans.size());
	for(PII i:ans) printf("%d %d\n",i.fi,i.se);
}