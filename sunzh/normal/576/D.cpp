#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<bitset>
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
int n,m;
struct edge{
	int u,v,d;
	bool operator <(const edge &x)const{
		return d<x.d;
	}
}e[160];
typedef bitset<160>bt;
struct mat{
	bt a[160];
}A,tmp;
bt T;
int dis[160];
mat operator *(mat x,mat y){
	mat res;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(x.a[i][j]) res.a[i]|=y.a[j];
		}
	}
	return res;
}
bt operator *(bt x,mat y){
	bt res;res.reset();
	for(int i=0;i<n;++i){
		if(x[i]) res|=y.a[i];
	}
	return res;
}
void ksm(bt&res,mat x,int k){
	mat t=x;
	while(k){
		if(k&1) res=res*t;
		t=t*t;k>>=1;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].d=read();
	}
	sort(e+1,e+m+1);
	T[0]=1;
	int last=0;
	int ans=2e9;
	for(int i=1;i<=m;++i){
		ksm(T,A,e[i].d-last);
		A.a[e[i].u-1][e[i].v-1]=1;
		queue<int>Q;
		for(int j=1;j<=n;++j){
			dis[j]=-1;
			if(T[j-1]) dis[j]=0,Q.push(j);
		}
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int j=1;j<=n;++j){
				if(dis[j]==-1&&A.a[u-1][j-1]){
					dis[j]=dis[u]+1;
					Q.push(j);
				}
			}
		}
		if(dis[n]!=-1) ans=min(ans,e[i].d+dis[n]);
		last=e[i].d;
	}
	if(ans>1e9+200) printf("Impossible\n");
	else printf("%d\n",ans);
}