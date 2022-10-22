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
int n,d;
int fa[1000010],sz[1000010];
set<PII>st;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	n=read(),d=read();
	for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1,st.insert(mp(1,i));
	int ans=1,sum=0;
	for(int i=1;i<=d;++i){
		int x=read(),y=read();
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			++sum;fa[fx]=fy;
			st.erase(mp(sz[fx],fx));st.erase(mp(sz[fy],fy));
			st.insert(mp(sz[fx]+sz[fy],fy));
			sz[fy]+=sz[fx];ans=max(ans,sz[fy]);
		}
		auto it=st.end();--it;
		int res=(it->fi);
		int k=i-sum;
		while(k--){
			if(it==st.begin()) break ;
			--it;
			res+=(it->fi);
		}
		printf("%d\n",res-1);
		// printf("%d\n",i-sum+ans-1);
	}
}