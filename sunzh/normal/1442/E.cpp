#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[200010];
vector<int>vec[200010];
queue<int>Q[3];
int deg[200010];
int solve(int x){
	if(n==1) return 1;
	for(int i=1;i<=n;++i) deg[i]=0;
	for(int i=1;i<=n;++i){
		for(int v:vec[i]) deg[v]++;
	}
	while(!Q[0].empty()) Q[0].pop();
	while(!Q[1].empty()) Q[1].pop();
	while(!Q[2].empty()) Q[2].pop();
	for(int i=1;i<=n;++i){
		if(deg[i]==1){
			if(a[i]==1) Q[0].push(i);
			else if(a[i]==2) Q[1].push(i);
			else Q[2].push(i);
		}
	}
	int res=0;
	while(Q[0].size()+Q[1].size()+Q[2].size()){
		x=x^1;
		bool t=0;
		while(Q[x].size()+Q[2].size()){
			int u;
			if(Q[x].size()){
				u=Q[x].front();Q[x].pop();
			}
			else{
				u=Q[2].front();Q[2].pop();
			}
			t=1;
			for(int v:vec[u]){
				deg[v]--;
				if(deg[v]==1){
					if(a[v]==1) Q[0].push(v);
					else if(a[v]==2) Q[1].push(v);
					else Q[2].push(v);
				}
			}
		}
		res+=t; 
	}
	return res;
}
int main(){
	T=read();
	while(T--){
		n=read();
		while(!Q[0].empty()) Q[0].pop();
		while(!Q[1].empty()) Q[1].pop();
		while(!Q[2].empty()) Q[2].pop();
		for(int i=1;i<=n;++i) vec[i].clear();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			vec[u].pb(v),vec[v].pb(u);
		}
		int ans=min(solve(0),solve(1));
		printf("%d\n",ans);
	}
}