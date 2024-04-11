#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int a[510][510];
struct node{
	int u,v,w;
	bool operator <(const node &x)const{
		if(w==x.w) return u<x.u;
		return w<x.w;
	}
}e[200010];
int cnt;
int v[200010];
int fa[200010];
int ncnt;
vector<int>vec[200010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read();
	ncnt=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			e[++cnt]=node{i,j,a[i][j]};
		}
		v[i]=a[i][i];
	}
	for(int i=1;i<=200000;++i) fa[i]=i;
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;++i){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy){
			if(v[fx]==e[i].w){
				fa[fy]=fx;vec[fx].pb(fy);
			}
			else if(v[fy]==e[i].w){
				fa[fx]=fy;vec[fy].pb(fx);
			}
			else{
				++ncnt;
//				if(ncnt==18){
//					printf("%d %d\n",fx,fy);
//				}
//				if(ncnt==19){
//					printf("fx:%d,fy:%d\n",fx,fy);
//				}
				fa[fx]=fa[fy]=ncnt;v[ncnt]=e[i].w;
				vec[ncnt].pb(fx);vec[ncnt].pb(fy);
			}
		}
	}
	printf("%d\n",ncnt);
	for(int i=1;i<=ncnt;++i) printf("%d ",v[i]);printf("\n");
	printf("%d\n",find(1));
	for(int i=1;i<=ncnt;++i){
		for(int j:vec[i]) printf("%d %d\n",j,i);
	}
}