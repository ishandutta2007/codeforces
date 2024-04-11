#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=410000;
int fa[N];
int bg[N];
int w[N];
int Q;
int n;
int lst;
int tr[19][N];
LL sw[19][N];
int sp[N];
void resu(int x){
	int t=fa[x];
	while(w[t]<w[x]&&t)t=bg[t];
	if(t)bg[x]=t;
	sp[x]=sp[bg[x]]+1;
	tr[0][x]=bg[x];
	sw[0][x]=w[x];
	rep(j,1,18){
		tr[j][x]=tr[j-1][tr[j-1][x]];
		sw[j][x]=sw[j-1][x]+sw[j-1][tr[j-1][x]];
	}
}
int ask(int x,LL up){
	int ans=0;
	int li=sp[x];
	per(i,18,0)if(sw[i][x]<=up&&(ans+(1<<i)<=li)){
		up-=sw[i][x];
		ans+=(1<<i);
		x=tr[i][x];
	}
	return ans;
}
void d1(){
	LL p,q;scanf("%lld%lld",&p,&q);
	int r=p^lst;
	int ww=q^lst;
	//printf("_%d %d\n",r,ww);
	++n;
	fa[n]=r;
	w[n]=ww;
	resu(n);
}
void d2(){
	LL p,q;scanf("%lld%lld",&p,&q);
	int r=p^lst;
	LL up=q^lst;
	//printf("__%d %lld\n",r,up);
	lst=ask(r,up);
	printf("%d\n",lst);
}
int main(){
	scanf("%d",&Q);
	n=1;
	w[1]=0;
	sp[1]=1;	
	while(Q--){
		int ty;scanf("%d",&ty);
		if(ty==1)d1();
		else d2();
	}
	return 0;
}