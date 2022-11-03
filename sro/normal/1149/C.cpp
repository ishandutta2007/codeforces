#include <bits/stdc++.h>
using namespace std;

struct Data{
	int wp;
	int mxd,mxm,mxl,mxr,mx;
	Data(){
		wp=mxd=mxm=mxl=mxr=mx=0;
	}
	void operator+=(const int &c){
		mxd+=c;
		mxm-=2*c;
		mxl-=c;
		mxr-=c;
		wp+=c;
	}
	Data operator+(const Data &dt){
		Data now;
		now.mxd=max(mxd,dt.mxd);
		now.mxm=max(mxm,dt.mxm);
		now.mxl=max(max(mxl,dt.mxl),mxd+dt.mxm);
		now.mxr=max(max(mxr,dt.mxr),mxm+dt.mxd);
		now.mx=max(max(mxd+dt.mxr,mxl+dt.mxd),max(mx,dt.mx));
		return now;
	}
};

Data dt[1600005];
int n,m;

void pushdown(int now){
	dt[now<<1]+=dt[now].wp;
	dt[now<<1|1]+=dt[now].wp;
	dt[now].wp=0;
}

void jar(int l,int r,int x,int now=1,int nl=1,int nr=m){
	pushdown(now);
	if(nl>=l&&nr<=r){
		dt[now]+=x;
		return;
	}
	if(nl>r||nr<l){
		return;
	}
	int m=(nl+nr)>>1;
	jar(l,r,x,now<<1,nl,m);
	jar(l,r,x,now<<1|1,m+1,nr);
	dt[now]=dt[now<<1]+dt[now<<1|1];
}

char s[200005];

int main(){
	int q;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	m=2*n-2;
	for(int i=1;i<=m;i++){
		if(s[i]=='('){
			jar(i,m,1);
		}else{
			jar(i,m,-1);
		}
	}
	printf("%d\n",dt[1].mx);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(s[l]=='('&&s[r]==')'){
			jar(l,m,-2);
			jar(r,m,2);
		}else if(s[l]==')'&&s[r]=='('){
			jar(l,m,2);
			jar(r,m,-2);
		}
		swap(s[l],s[r]);
		printf("%d\n",dt[1].mx);
	}
	return 0;
}