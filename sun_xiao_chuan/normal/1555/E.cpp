#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m;
int t[5000050],tag[5000050],a[5000050],tmp,tmp2;
 
inline void refresh(int now){
	t[now]=min(t[now<<1],t[now<<1|1]);
}
void build(int l,int r,int now){
	if(l==r){
		t[now]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
	refresh(now);
}
void pushdown(int l,int r,int now){
	if(l==r){
		tag[now]=0;
		return;
	}
	tag[now<<1]+=tag[now];
	tag[now<<1|1]+=tag[now];
	int mid=(l+r)>>1;
	t[now<<1]+=tag[now];
	t[now<<1|1]+=tag[now];
	tag[now]=0;
}
void add(int l,int r,int now,int LL,int RR,ll data){
	if(LL<=l&&r<=RR){
		t[now]+=data;
		tag[now]+=data;
		return;
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;
	if(LL<=mid) add(l,mid,now<<1,LL,RR,data);
	if(mid<RR) add(mid+1,r,now<<1|1,LL,RR,data);
	refresh(now);
}
int query(int l,int r,int now,int LL,int RR){
	if(LL<=l&&r<=RR){
		return t[now];
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;int ans=10;
	if(LL<=mid) ans=min(query(l,mid,now<<1,LL,RR),ans);
	if(mid<RR) ans=min(ans,query(mid+1,r,now<<1|1,LL,RR));
	refresh(now);
	return ans;
}
 
vector< pair<int,int> >v[1005000];
int res=1e8,it=1,l,r;
 
int main(){
	scanf("%d%d",&m,&n);
	add(1,n,1,1,1,1);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&k);
		v[k].push_back({l,r});
	}
	for(i=1;i<=1000000;i++){
		for(auto [l,r]:v[i]){
			add(1,n,1,l+1,r,1);
		}
		while(1){
			k=query(1,n,1,1,n);
			if(k){
				res=min(res,i-it);
				for(auto [l,r]:v[it]){
					add(1,n,1,l+1,r,-1);
				}
				it++;
			}
			else{
				break;
			}
		}
	}
	printf("%d",res);
	
}