// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<class T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

#define N 100005

vector<pii>adj[N];
int ans[N];
int n;

void dfs(int u,int fa,int las){
	for(auto v:adj[u]){
		if(v.fir==fa)continue;
		ans[v.sec]=1^las;
		dfs(v.fir,u,ans[v.sec]);
	}
}

void Solve(){
	n=read();
	rep(i,1,n)adj[i].clear();
	rep(i,1,n-1){
		int u=read(),v=read();
		adj[u].pb({v,i}),adj[v].pb({u,i});
	}	
	int S=0;
	rep(i,1,n){
		if(SZ(adj[i])>2){
			puts("-1");
			return;
		}
		if(SZ(adj[i])==1){
			S=i;
		}
	}
//	printf("S=%d\n",S);
	dfs(S,0,0);
	rep(i,1,n-1){
		if(ans[i])printf("3 ");
		else printf("2 "); 
	}
	puts("");
}

int main(){
	int T=read();
	while(T--){
		Solve();
	}
	return 0;
}