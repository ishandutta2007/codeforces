#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<random>
#include<chrono>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int u,v,p;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(SEED);
int opt[100010];
int cnt;
vector<int>V;
int getlen(int x,int y){
	if(!x) return 0;
	return getlen(y%x,x)+(y/x)+1;
}
void getpt(int x,int y){
	if(!x) return ;
	while(y>=x){
		y-=x;V.pb(1);
	}
	if(y){
		V.pb(2);
	}
	getpt(y,x);
}
void getpath(int x,int op){
	int a=rnd()%(p-1)+1;
	while(getlen(a,1ll*a*x%p)>100){
		a=rnd()%(p-1)+1;
	}
	V.clear();getpt(a,1ll*a*x%p);
	if(op) reverse(V.begin(),V.end());
	for(int i:V){
		if(i==1) opt[++cnt]=i^op;else opt[++cnt]=i;
	}
}
int main(){
	u=read(),v=read(),p=read();
	getpath(u,0);
	getpath(v,1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i) printf("%d ",opt[i]+1);
	return 0;
}