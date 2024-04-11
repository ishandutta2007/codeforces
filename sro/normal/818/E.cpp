#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100005];

struct segtree{
	int dt[1600005];
	void change(int to,int x,int now=1,int nl=1,int nr=n){
		if(nl==to&&nr==to){
			dt[now]=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			change(to,x,now<<1,nl,m);
		}else{
			change(to,x,now<<1|1,m+1,nr);
		}
		dt[now]=1ll*dt[now<<1]*dt[now<<1|1]%k;
	}
	int get(int l,int r,int now=1,int nl=1,int nr=n){
		if(nl>=l&&nr<=r){
			return dt[now];
		}
		if(nl>r||nr<l){
			return 1%k;
		}
		int m=(nl+nr)>>1;
		return 1ll*get(l,r,now<<1,nl,m)*get(l,r,now<<1|1,m+1,nr)%k;
	}
}seg;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		seg.change(i,a[i]%k);
	}
	int r=1;
	long long ans=0;
	for(int l=1;l<=n;l++){
		r=max(r,l);
		while(r<=n&&seg.get(l,r)){
			r++;
		}
		ans+=n-r+1;
	}
	printf("%lld\n",ans);
	return 0;
}