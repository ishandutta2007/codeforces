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
int n;
int p[2049];
map<PII,int>Map;
int query(int u,int v){
	if(u>v) swap(u,v);
	if(Map.count(mp(u,v))) return Map[mp(u,v)];
	printf("? %d %d\n",u,v);fflush(stdout);return Map[mp(u,v)]=read();
}
int ans[2050];
int main(){
	n=read();
	for(int i=1;i<=n;++i) p[i]=i;
	random_shuffle(p+1,p+n+1);
	int a=1,b=2;
	int nw=query(p[1],p[2]);
	for(int i=3;i<=n;++i){
		int t=query(p[a],p[i]);
		if(t<nw){
			b=i;nw=t;
		}
		else if(t==nw){
			a=i;nw=query(p[b],p[i]);
		}
	}
	a=p[a],b=p[b];
	random_shuffle(p+1,p+n+1);
	for(int i=1;i<=n;++i) if(p[i]!=a&&p[i]!=b) {
		int t=query(a,p[i]),q=query(b,p[i]);
		if(t!=q){
			if(t>q) swap(a,b);break ;
		}
	}
	for(int i=1;i<=n;++i) ans[i]=(a==i?0:query(a,i));
	printf("! ");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}