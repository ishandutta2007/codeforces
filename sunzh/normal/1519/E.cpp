#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define ep emplace_back
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
typedef long long ll;
int n;
int a[400010],b[400010],c[400010],d[400010];
map<PLL,int>idx;
int ncnt;
int getd(int f1,int g1,int f2,int g2){
	ll f=1ll*f2*g1,g=1ll*f1*g2;
	ll gcd=__gcd(f,g);
	f=f/gcd,g=g/gcd;
	if(idx.count(mp(f,g))) return idx[mp(f,g)];
	else return idx[mp(f,g)]=++ncnt;
}
vector<PII >vec[400010];
vector<PII>ans;
int dep[400010];
bool vis[400010];
bool dfs(int x,int fa,int up=-1){
	dep[x]=dep[fa]+1;vis[x]=1;
	int lst=-1;
	for(PII i:vec[x]){
		int v=i.fi;
		if(i.se==up){
			up=up;
		}
		else if(!vis[v]){
			if(dfs(v,x,i.se)){
				if(lst==-1){
					lst=i.se;
				}
				else ans.ep(lst,i.se),lst=-1;
			}
		}
		else if(dep[v]<dep[x]){
			if(lst==-1){
				lst=i.se;
			}
			else ans.ep(lst,i.se),lst=-1;
		}
	}
	if(up!=-1&&lst!=-1) {
		ans.ep(up,lst);return 0;
	}
	return 1;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read(),c[i]=read(),d[i]=read();
		int d1=getd(a[i]+b[i],b[i],c[i],d[i]);
		int d2=getd(a[i],b[i],c[i]+d[i],d[i]);
		vec[d1].ep(d2,i);vec[d2].ep(d1,i);
	} 
	for(int i=1;i<=ncnt;++i) if(!vis[i]) dfs(i,0);
	printf("%d\n",ans.size());
	for(PII i:ans) printf("%d %d\n",i.fi,i.se);
}