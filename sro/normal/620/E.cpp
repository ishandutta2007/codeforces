#include <bits/stdc++.h>
using namespace std;

int n,m;

struct Segtree{
	long long dt[3200005];
	long long wc[3200005];
	void pushdown(int now){
		if(wc[now]){
			dt[now<<1]=wc[now];
			dt[now<<1|1]=wc[now];
			wc[now<<1]=wc[now];
			wc[now<<1|1]=wc[now];
			wc[now]=0;
		}
	}
	void pushup(int now){
		dt[now]=(dt[now<<1]|dt[now<<1|1]);
	}
	void change(int l,int r,long long x,int now=1,int nl=1,int nr=n){
		pushdown(now);
		if(nl>=l&&nr<=r){
			dt[now]=wc[now]=x;
			return;
		}
		if(nl>r||nr<l){
			return;
		}
		int m=(nl+nr)>>1;
		change(l,r,x,now<<1,nl,m);
		change(l,r,x,now<<1|1,m+1,nr);
		pushup(now);
	}
	long long get(int l,int r,int now=1,int nl=1,int nr=n){
		pushdown(now);
		if(nl>=l&&nr<=r){
			return dt[now];
		}
		if(nl>r||nr<l){
			return 0;
		}
		int m=(nl+nr)>>1;
		return get(l,r,now<<1,nl,m)|get(l,r,now<<1|1,m+1,nr);
	}
}seg;

int dfi[400005],dfo[400005],tmc;
vector<int> nei[400005];
int c[400005];

void dfs(int now,int lst){
	dfi[now]=++tmc;
	for(int i=0;i<nei[now].size();i++){
		if(nei[now][i]!=lst){
			dfs(nei[now][i],now);
		}
	}
	dfo[now]=tmc;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		seg.change(dfi[i],dfi[i],1ll<<c[i]);
	}
	while(m--){
		int mode;
		scanf("%d",&mode);
		if(mode==1){
			int to,c;
			scanf("%d%d",&to,&c);
			seg.change(dfi[to],dfo[to],1ll<<c);
		}else{
			int to;
			scanf("%d",&to);
			int ss=0;
			long long val=seg.get(dfi[to],dfo[to]);
			for(int i=1;i<=60;i++){
				ss+=((val>>i)&1);
			}
			printf("%d\n",ss);
		}
	}
	return 0;
}