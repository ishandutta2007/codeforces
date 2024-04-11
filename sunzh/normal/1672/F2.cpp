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
int a[200010],b[200010];
vector<int>vec[200010];
int deg[200010];
int cnt[200010];
int main(){
	T=read();
	for(int o=1;o<=T;++o){
		n=read();
		for(int i=1;i<=n;++i) cnt[i]=deg[i]=0;
		for(int i=1;i<=n;++i) a[i]=read(),++cnt[a[i]];
		for(int i=1;i<=n;++i) b[i]=read(),++deg[a[i]];
		bool fl=1;
		for(int i=1;i<=n;++i) if(cnt[i]!=deg[i]) fl=0;
		if(!fl){
			printf("WA\n");continue ;
		}
		for(int i=1;i<=n;++i) vector<int>().swap(vec[i]),deg[i]=0;
		for(int i=1;i<=n;++i){
			vec[b[i]].pb(a[i]);deg[a[i]]++;
		}
		int mx=0;
		for(int i=1;i<=n;++i) if(cnt[i]>cnt[mx]) mx=i;
		deg[mx]=0;
		queue<int>Q;Q.push(mx);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int v:vec[u]){
				if(--deg[v]==0){
					Q.push(v);
				}
			}
		}
		for(int i=1;i<=n;++i) if(deg[i]>0) fl=0;
		if(!fl) printf("WA\n");else printf("AC\n");
	}
}