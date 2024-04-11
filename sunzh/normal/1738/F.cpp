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
#include<random>
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
int deg[1010];
int fa[1010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool used[1010];
int col[1010];
int main(){
	T=read();
	while(T--){
		n=read();
		priority_queue<PII>Q;
		for(int i=1;i<=n;++i) deg[i]=read(),fa[i]=i,Q.push(mp(deg[i],i)),used[i]=0;
		while(!Q.empty()){
			PII u=Q.top();Q.pop();
			if(used[u.se]) continue ;
			used[u.se]=1;
			for(int i=1;i<=deg[u.se];++i){
				printf("? %d\n",u.se);fflush(stdout);
				int x=read();
				if(!used[x]){
					used[x]=1;fa[find(x)]=find(u.se);
				}
				else{
					fa[find(u.se)]=find(x);break ;
				}
			}
		}
		int c=0;
		for(int i=1;i<=n;++i) if(find(i)==i) col[i]=++c;
		printf("! ");
		for(int i=1;i<=n;++i) printf("%d ",col[find(i)]);printf("\n");fflush(stdout);
	}
}