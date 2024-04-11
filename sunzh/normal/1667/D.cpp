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
int T;
int n;
int deg[200010];
vector<int>vec[200010];
int prt[200010];
bool fl;
void dfs0(int x,int fa){
	int cnt[2]={0,0};
	for(int v:vec[x]) if(v!=fa){
		dfs0(v,x);
		cnt[prt[v]]++;
	}
	if(x==1){
		if(cnt[1]==cnt[0]+1) prt[x]=0;
		else if(cnt[1]==cnt[0]) prt[x]=1;
		else fl=1;
		return ;
	}
	if(cnt[0]==cnt[1]) prt[x]=1;
	else if(cnt[0]==cnt[1]+1) prt[x]=1;
	else if(cnt[1]==cnt[0]+1||cnt[1]==cnt[0]+2) prt[x]=0;
	else fl=1;
}
vector<PII>ans;
void solve(int x,int fa){
	// printf("x:%d,fa:%d\n",x,fa);
	if(x==1){
		vector<int>s[2];
		for(int v:vec[x]){
			s[prt[v]].pb(v);
		}
		// printf("%d %d\n",s[0].size(),s[1].size());
		bool f=prt[x];
		while(s[0].size()||s[1].size()){
			f^=1;
			solve(s[f].back(),x);
			s[f].pop_back();
		}
	}
	else{
		bool f=(vec[x].size()&1);
		vector<int>s[2];
		for(int v:vec[x]) if(v!=fa){
			s[prt[v]].pb(v);
		}
		s[prt[x]].pb(fa);f^=1;
		// printf("%d %d\n",s[0].size(),s[1].size());
		while(s[0].size()||s[1].size()){
			f^=1;
			if(s[f].back()==fa){
				ans.pb(mp(x,fa));s[f].pop_back();continue ;
			}
			solve(s[f].back(),x);
			s[f].pop_back();
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) vector<int>().swap(vec[i]),deg[i]=0;
		for(int i=1;i<n;++i){
			int u=read(),v=read();vec[u].pb(v);vec[v].pb(u);++deg[u],++deg[v];
		}
		fl=0;
		dfs0(1,0);
		if(fl){
			puts("NO");continue ;
		}
		puts("YES");
		ans.clear();
		solve(1,0);
		for(PII i:ans) printf("%d %d\n",i.fi,i.se);
	}
}