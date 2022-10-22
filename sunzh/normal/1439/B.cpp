//#pragma GCC optmize(3)
#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<chrono>
#include<ctime>
#include<random>
#include<unordered_set>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define pow powl
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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(int x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x<<15 + FIXED_RANDOM)^(splitmix64(x + FIXED_RANDOM) >> 1);
	}
};
int T;
int n,m,k;
vector<int>vec[100010];
unordered_set<int,custom_hash >Map[100010];
int deg[100010];
bool vis[100010];
int main(){
//	srand(time(NULL));
	T=read();
	while(T--){
		int cnt=0;
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i) vector<int>().swap(vec[i]),unordered_set<int,custom_hash >().swap(Map[i]),deg[i]=vis[i]=0;
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			vec[u].pb(v),vec[v].pb(u);++deg[u],++deg[v];Map[u].emplace(v);Map[v].emplace(u);
		}
		if(ceil(sqrtl(m*2))<k){
			printf("-1\n");continue ;
		}
		for(int i=1;i<=n;++i) if(deg[i]>=k-1) ++cnt;
		if(cnt<k){
			printf("-1\n");continue ;
		}
		queue<int>Q;
		for(int i=1;i<=n;++i){
			if(deg[i]<k) Q.push(i);
		}
		bool f=0;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			vis[u]=1;
			if(deg[u]==k-1){
				vector<int>V;
				V.push_back(u);
				for(int v:vec[u])
				if(!vis[v]){
					V.pb(v);
					if(deg[v]==k){
						Q.push(v);
					}
					--deg[v];
				}
				bool no=0;
				for(int i=0;i<k;++i){
					for(int j=i+1;j<k;++j){
//						printf("%d %d\n",/V[i],V[j]);
						if(!Map[V[i]].count(V[j])){
							no=1;goto tmp;
						}
					}
				}
				f=1;
				printf("2\n");
				for(int i=0;i<k;++i) printf("%d ",V[i]);printf("\n");
				break ;
				tmp: ;
			}
			else{
				for(int v:vec[u])
				if(!vis[v]){
					if(deg[v]==k) Q.push(v);
					--deg[v];
				}
			}
		}
		if(!f){
			int c=0;
			for(int i=1;i<=n;++i) if(!vis[i]) ++c;
			if(c){
				printf("1 %d\n",c);
				for(int i=1;i<=n;++i) if(!vis[i]) printf("%d ",i);
				printf("\n");
			}
			else printf("-1\n");
		}
	}
}