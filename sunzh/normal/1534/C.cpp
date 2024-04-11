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
int a[2][400010];
int fa[400010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
const int mod=1e9+7;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int o=0;o<2;++o) for(int i=1;i<=n;++i) a[o][i]=read();
		int ans=1;
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=n;++i) fa[find(a[0][i])]=find(a[1][i]);
		for(int i=1;i<=n;++i) if(fa[i]==i){
			ans=(ans<<1)%mod;
		}
		printf("%d\n",ans);
	}
}