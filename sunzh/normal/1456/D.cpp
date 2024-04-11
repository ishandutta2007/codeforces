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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int f[5010],g[5010],h[5010];
int t[5010],pos[5010];
int n;
bool can[5010][5010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) t[i]=read(),pos[i]=read();
	f[0]=1;
	auto cango=[&](int x,int y){
		return t[y]-t[x]>=abs(pos[y]-pos[x]);
	};
	for(int i=0;i<=n;++i){
		can[i][i]=1;
		for(int j=i+1;j<=n;++j){
			if(cango(j-1,j)) can[i][j]=1;
			else break ;
		}
	}
	memset(g,-1,sizeof(g));
	for(int i=0;i<n;++i){
		if(f[i]){
			if(can[i][i+1]){
				f[i+1]=1;
				if(g[i+1]==-1) g[i+1]=t[i]+abs(pos[i+1]-pos[i]);
				else g[i+1]=min(g[i+1],t[i]+abs(pos[i+1]-pos[i]));
			}
			for(int j=i+2;j<=n;++j){
				if(abs(pos[j]-pos[i])+abs(pos[i+1]-pos[j])<=t[i+1]-t[i]&&can[i+1][j-1]) h[j]=1;
			}
		}
		if(g[i]!=-1){
			if(abs(pos[i+1]-pos[i])<=t[i+1]-g[i]){
				f[i+1]=1;
				int val=max(t[i],g[i]+abs(pos[i+1]-pos[i]));
				if(g[i+1]==-1){
					g[i+1]=val;
				}
				else g[i+1]=min(g[i+1],val);
			}
			for(int j=i+2;j<=n;++j){
				if(max(t[i],abs(pos[j]-pos[i])+g[i])<=t[i+1]-abs(pos[i+1]-pos[j])&&can[i+1][j-1]) h[j]=1;
			}
		}
		if(h[i]){
			if(t[i+1]-t[i-1]>=abs(pos[i+1]-pos[i-1])){
				f[i+1]=1;
				if(g[i+1]==-1) g[i+1]=max(t[i],t[i-1]+abs(pos[i+1]-pos[i-1]));
				else g[i+1]=min(g[i+1],max(t[i],t[i-1]+abs(pos[i+1]-pos[i-1])));
			}
			for(int j=i+2;j<=n;j++){
				int T=max(t[i],t[i-1]+abs(pos[j]-pos[i-1]));
				if(T+abs(pos[j]-pos[i+1])<=t[i+1]){
					if(can[i+1][j-1]) h[j]=1;
				}
			}
		}
	}
	if(f[n]||h[n]||g[n]!=-1) printf("YES\n");
	else printf("NO\n");
	return 0;
}