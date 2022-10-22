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
int h,g;
int a[1<<21|1];
vector<int>ope;
int getdep(int x){
	int d=0;
	while(x) ++d,x>>=1;return d;
}
void del(int x){
	if(!a[x<<1]&&!a[x<<1|1]){
		a[x]=0;return ;
	}
	if(a[x<<1]>a[x<<1|1]){
		a[x]=a[x<<1];del(x<<1);
	}
	else a[x]=a[x<<1|1],del(x<<1|1);
}
int check(int x){
	if(!a[x<<1]&&!a[x<<1|1]){
		;return x;
	}
	if(a[x<<1]>a[x<<1|1]) return check(x<<1);
	else return check(x<<1|1);
}
void dfs(int x){
	if(!a[x]) return ;
	while(getdep(check(x))>g){
		del(x);ope.pb(x);
	}
	dfs(x<<1);dfs(x<<1|1);
}
int main(){
	T=read();
	while(T--){
		h=read(),g=read();
		for(int i=1;i<(1<<h);++i) a[i]=read();
		for(int i=(1<<h);i<(1<<h+1);++i) a[i]=0;ope.clear();
		dfs(1);
		long long ans=0;
		for(int i=1;i<(1<<g);++i) ans+=a[i];
		printf("%lld\n",ans);for(int i:ope) printf("%d ",i);printf("\n");
	}
}