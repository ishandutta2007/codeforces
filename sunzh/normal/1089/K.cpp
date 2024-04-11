#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int Q;
const int N=1000000;
int sum[4000010],maxn[4000010];
PII a[300010];

void pushup(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
	maxn[p]=max(maxn[p<<1|1],maxn[p<<1]+sum[p<<1|1]);
}
void update(int p,int l,int r,int pos,int k){
	if(l==r){
		sum[p]+=k;
		maxn[p]=sum[p]+l;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);
	else update(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
PII query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return mp(sum[p],maxn[p]);
	}
	int mid=l+r>>1;
	PII res=query(p<<1,l,mid,L,R);;
	PII tmp;
	if(R>mid) tmp=query(p<<1|1,mid+1,r,L,R);
	else tmp=mp(0,0);
	res.fi+=tmp.fi;res.se=max(tmp.se,res.se+tmp.fi);
	return res;
}
signed main(){
	Q=read();
	for(int i=1;i<=Q;++i){
		char c=getchar();
		while(c!='+'&&c!='-'&&c!='?') c=getchar();
		switch(c){
			case '+':{
				int x=read(),d=read();
				a[i]=mp(x,d);
				update(1,1,N,x,d); 
				break;
			}
			case '-':{
				int x=read();
				update(1,1,N,a[x].fi,-a[x].se);
				break;
			}
			case '?':{
				int x=read();
				printf("%lld\n",max(0ll,query(1,1,N,1,x).se-x));
				break;
			}
		}
	}
	return 0;
}