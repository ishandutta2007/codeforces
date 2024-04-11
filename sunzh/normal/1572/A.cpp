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
vector<int>vec[200010],edg[200010];
int out[200010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) vec[i].clear(),out[i]=0,edg[i].clear();
		for(int i=1;i<=n;++i){
			int k=read();out[i]=k;
			for(int j=1;j<=k;++j){
				int u=read();vec[i].pb(u);edg[u].pb(i);
			}
		}
		priority_queue<int,vector<int>,greater<int> >Q1,Q2;
		for(int i=1;i<=n;++i) if(!out[i]) Q1.push(i);
		int cnt=Q1.size(),ans=1;
		while(Q1.size()||Q2.size()){
			if(!Q1.size()) swap(Q1,Q2),++ans;
			int u=Q1.top();Q1.pop();
			for(int v:edg[u]){
				if(!--out[v]){
					if(v>u) Q1.push(v);
					else Q2.push(v);++cnt;
				}
			}
		}
		if(cnt!=n) puts("-1");
		else printf("%d\n",ans);
	}
}