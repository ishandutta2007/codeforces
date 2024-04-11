#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=(1<<16)+5;
vector<int> go[N];
int n;
int w[N];
void work(vector<int> now){
	if(now.size()==0)return;
	vector<int> g;
	for(int x:now)for(int y:go[x])if(w[y]==-1){
		g.pb(y);w[y]=-2;
	}
	for(int x:g){
		w[x]=0;
		for(int y:go[x])if(w[y]>=0)w[x]|=w[y];
	}
	work(g);
}
int re[N];
void Main(){
	scanf("%d",&n);
	rep(i,0,(1<<n)-1)go[i].clear(),w[i]=-1;
	rep(i,1,n*(1<<(n-1))){
		int a,b;scanf("%d%d",&a,&b);
		go[a].pb(b);
		go[b].pb(a);
	}
	w[0]=0;
	vector<int> now;
	for(int i=0;i<go[0].size();i++)w[go[0][i]]=(1<<i),now.pb(go[0][i]);
	work(now);
	rep(i,0,(1<<n)-1)re[w[i]]=i;
	rep(i,0,(1<<n)-1)printf("%d ",re[i]);puts("");
	if((1<<(n-1))%n!=0)puts("-1");
	else{
		rep(i,0,(1<<n)-1){
			int col=0;
			rep(j,0,n-1)if(w[i]&(1<<j))col^=j;
			printf("%d ",col);
		}
		puts("");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;
}