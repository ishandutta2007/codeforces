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
int n,x;
vector<int>vec[100010];
int fa[100010];
int dep[100010];
int sz[100010];
int mxd;
int Cnt[100010];
vector<int>V[100010],D[100010];
void dfs(int x){
	++sz[dep[x]];D[dep[x]].pb(x);
	mxd=max(mxd,dep[x]);
	for(int v:vec[x]){
		dep[v]=dep[x]+1;
		dfs(v);
	}
}
vector<int>st[510];
int val[510],cnt[510];
int tot;
int k[450][100010];
bool f[450][100010];
bool col[100010];
void getans(){
	int T=x;
	memset(col,1,sizeof(col));
	for(int i=tot;i>=1;--i){
		for(int j=0;j<k[i][T];++j){
//			printf("i:%d,j:%d\n",i,j);
			for(int l:D[st[i][j]]) col[l]=0;
		}
		T-=k[i][T]*val[i];
	}
}
int main(){
	n=read(),x=read();
	for(int i=2;i<=n;++i) fa[i]=read(),vec[fa[i]].pb(i);
	dep[1]=1;
	dfs(1);
	for(int i=1;i<=n;++i){
		++Cnt[sz[i]];V[sz[i]].pb(i);
	}
	for(int i=1;i<=n;++i){
		if(Cnt[i]){
			val[++tot]=i;cnt[tot]=Cnt[i];
			st[tot]=move(V[i]);
		}
	}
	memset(k,0x3f,sizeof(k));
	f[0][0]=1;k[0][0]=0;
//	printf("tot:%d\n",tot);
	for(int i=1;i<=tot;++i){
		for(int j=0;j<=x;++j){
			if(f[i-1][j]) k[i][j]=0;
			if(j>=val[i]) k[i][j]=min(k[i][j],k[i][j-val[i]]+1);
			if(k[i][j]<=cnt[i]) f[i][j]=1;
			else k[i][j]=0x3f3f3f3f;
//			printf("f[%d][%d]=%d\nk[%d][%d]=%d\n",i,j,f[i][j],i,j,k[i][j]);
		}
	}
	if(f[tot][x]){
		getans();
		printf("%d\n",mxd);
	}
	else{
		printf("%d\n",mxd+1);
		int A=x,B=n-x;
		for(int i=1;i<=mxd;++i){
			if(A>sz[i]){
				for(int j:D[i]) col[j]=0;
				A-=sz[i];
			}
			else{
				int ct=0;
				vector<int>nson,leaf;
				for(int j:D[i]){
					if(vec[j].size()) ++ct,nson.pb(j);
					else leaf.pb(j);
				}
				if(A>=ct){
					for(int j:nson){
						col[j]=0;
					}
					A-=ct;
					for(int j=0;j<A;++j) col[leaf[j]]=0;
					for(int j=A;j<leaf.size();++j) col[leaf[j]]=1;A=0;
				}
				else{
					for(int j:nson){
						col[j]=1;
					}
					if(A<=leaf.size()){
					for(int j=0;j<A;++j) col[leaf[j]]=0;
					for(int j=A;j<leaf.size();++j) col[leaf[j]]=1;A=0;
					}
					else for(int j=0;j<leaf.size();++j) col[leaf[j]]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i) putchar('a'+col[i]);
}