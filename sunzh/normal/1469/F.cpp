#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int l[200010];
const int N=500010;
long long sum[2000010],tag[2000010];
void pushdown(int p,int l,int r){
	if(tag[p]){
		int mid=l+r>>1;
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		sum[p<<1]+=1ll*tag[p]*(mid-l+1);
		sum[p<<1|1]+=1ll*tag[p]*(r-mid);
		tag[p]=0;
	}
}
void pushup(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
int binery_search(int p,int l,int r,int k){
	if(l==r) return l;
	int mid=l+r>>1;
	pushdown(p,l,r);
	if(sum[p<<1]>=k) return binery_search(p<<1,l,mid,k);
	else return binery_search(p<<1|1,mid+1,r,k-sum[p<<1]);
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		sum[p]+=1ll*k*(r-l+1);tag[p]+=k;
		return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int n,k;
int main(){
	n=read(),k=read();
	long long tot=1;
	for(int i=1;i<=n;++i) l[i]=read(),tot+=l[i]-2;
	if(tot<k){
		printf("-1\n");return 0;
	}
	int ans=0x3f3f3f3f;
	sort(l+1,l+n+1);reverse(l+1,l+n+1);
	update(1,1,N,1,1,1);
	for(int i=1;i<=n;++i){
		int ps=binery_search(1,1,N,1);
		update(1,1,N,ps,ps,-1);
		--l[i];
		int ls=l[i]>>1,rs=l[i]-ls;
		update(1,1,N,ps+2,ps+ls+1,1);
		update(1,1,N,ps+2,ps+rs+1,1);
		if(sum[1]>=k){
			ans=min(ans,binery_search(1,1,N,k)-1);
		}
	}
	printf("%d\n",ans==0x3f3f3f3f?-1:ans);
	return 0;
}