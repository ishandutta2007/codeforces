#include<bits/stdc++.h>
#define N 200005
#define mid (l+r>>1)
using namespace std;
int n,k,a[N],cov[N<<2],mx[N],mn[N];
inline void pd(int x){
	if(cov[x])
	cov[x<<1]=cov[x<<1|1]=cov[x],cov[x]=0;
}
void mdf(int x,int l,int r,int ll,int rr,int v){
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr){cov[x]=v;return;}
	pd(x);
	mdf(x<<1,l,mid,ll,rr,v);
	mdf(x<<1|1,mid+1,r,ll,rr,v);
}
void dfs(int x,int l,int r){
	if(l<r)pd(x),dfs(x<<1,l,mid),dfs(x<<1|1,mid+1,r);
	else mn[l]=cov[x];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		mx[a[i]]=i;
		if(!mn[a[i]])mn[a[i]]=i;
	}
	cov[1]=1;
	for(int i=2;i<=k;i++)
	if(mx[i]){
		mdf(1,1,n,mn[i],mx[i],i);
	}
	else if(i==k){
        if(!mx[0])return puts("NO"),0;
        mdf(1,1,n,mx[0],mx[0],k);
	}
	dfs(1,1,n);
	for(int i=1;i<=n;i++)
	if(a[i]&&a[i]^mn[i])return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++)
	printf("%d ",mn[i]);
}