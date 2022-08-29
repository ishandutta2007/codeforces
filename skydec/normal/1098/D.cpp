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
const int N=510000;
int n;
int w[N];
int tmp[N];int m;
LL cnt[N];
void add(int x,int v){
	for(;x<=m;x+=(x&(-x)))cnt[x]+=v;
}
LL ask(int x){
	LL ans=0;
	for(;x;x-=(x&(-x)))ans+=cnt[x];
	return ans;
}

set<int>gt;
int tt[N];
int sz;
void addit(int x){
	tt[x]++;
	if(tt[x]==1)gt.insert(tmp[x]);
	add(x,tmp[x]);
	++sz;
}
void delit(int x){
	tt[x]--;
	if(tt[x]==0)gt.erase(tmp[x]);
	--sz;
	add(x,-tmp[x]);
}
int gkd(){
	LL now=*gt.begin();

	int ans=0;

	while(1){
		if(now>1e9)break;
		if(gt.upper_bound(2*now)!=gt.end()){
			int t=*gt.upper_bound(2*now);
			t=lower_bound(tmp+1,tmp+1+m,t)-tmp;
			LL w=ask(t-1);
			if(2ll*w<tmp[t])++ans;
			now=w+tmp[t];
		}
		else break;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		char op[4];scanf("%s",op+1);
		if(op[1]=='+'){
			scanf("%d",&w[i]);
			tmp[++m]=w[i];
		}
		else{
			scanf("%d",&w[i]);
			tmp[++m]=w[i];
			w[i]=-w[i];
		}
	}
	sort(tmp+1,tmp+1+m);
	m=unique(tmp+1,tmp+1+m)-tmp-1;
	rep(i,1,n){
		if(w[i]>0)w[i]=lower_bound(tmp+1,tmp+1+m,w[i])-tmp;
		else w[i]=-(lower_bound(tmp+1,tmp+1+m,-w[i])-tmp);
	}

	rep(i,1,n){
		if(w[i]>0)addit(w[i]);
		else delit(-w[i]);
		if(!sz)printf("0\n");else
		printf("%d\n",sz-1-gkd());
	}

	return 0;
}