#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> hv[100005];
int dt[2000005],L[2000005],R[2000005],nds;
int root[100005];

void change(int &now,int to,int x,int nl=0,int nr=n){
	L[++nds]=L[now];
	R[nds]=R[now];
	dt[nds]=dt[now]+x;
	now=nds;
	if(nl==to&&nr==to){
		return;
	}
	int m=(nl+nr)>>1;
	if(m>=to){
		change(L[now],to,x,nl,m);
	}else{
		change(R[now],to,x,m+1,nr);
	}
}

int get(int now1,int now2,int l,int r,int nl=0,int nr=n){
	if(nl>=l&&nr<=r){
		return dt[now2]-dt[now1];
	}
	if(nl>r||nr<l){
		return 0;
	}
	int m=(nl+nr)>>1;
	return get(L[now1],L[now2],l,r,nl,m)+get(R[now1],R[now2],l,r,m+1,nr);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int ai;
		scanf("%d",&ai);
		hv[ai].push_back(i);
		int to=0;
		if(hv[ai].size()>k){
			to=hv[ai][hv[ai].size()-k-1];
		}
		root[i]=root[i-1];
		change(root[i],to,1);
	}
	scanf("%d",&k);
	int sh=0;
	while(k--){
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+sh)%n+1;
		r=(r+sh)%n+1;
		if(l>r){
			swap(l,r);
		}
		printf("%d\n",sh=get(root[l-1],root[r],0,l-1));
	}
	return 0;
}