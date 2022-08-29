#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
int mi[MAXN*4],num[MAXN*4];int aft[MAXN];int n,m;
int a[MAXN],kiss[MAXN];int lazy[MAXN*4];
inline void down(int x){
		lazy[x*2]+=lazy[x];
		mi[x*2]-=lazy[x];
		lazy[x*2+1]+=lazy[x];
		mi[x*2+1]-=lazy[x];
		lazy[x]=0;
}
inline void updata(int x){
		mi[x]=mi[x*2];num[x]=num[x*2];
		if(mi[x*2+1]==mi[x]){
				num[x]+=num[x*2+1];
			}
		else if(mi[x*2+1]<mi[x]){
				mi[x]=mi[x*2+1];
				num[x]=num[x*2+1];
			}
		return;
}
void build(int x,int l,int r){
		if(l==r){
				mi[x]=aft[a[l]]-a[l];
				kiss[l]=aft[a[l]];
				num[x]=1;
				return;
		}
		int mid=(l+r)>>1;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		updata(x);
}
void add(int now,int l,int r,int x,int y,int v){
		if(l^r)down(now);
		if(x<=l&&r<=y){
				lazy[now]+=v;
				mi[now]-=v;
				return;
			}
		int mid=(l+r)>>1;
		if(x<=mid)add(now*2,l,mid,x,y,v);
		if(y>mid)add(now*2+1,mid+1,r,x,y,v);
		updata(now);
}
int count(int now,int l,int r,int x,int y){
		if(l^r)down(now);
		if(x<=l&&r<=y){
				if(mi[now]==0)return num[now];
				else return 0;
			}
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid)res+=count(now*2,l,mid,x,y);
		if(y>mid)res+=count(now*2+1,mid+1,r,x,y);
		return res;
}
void ck(int now,int l,int r){
		if(l^r)down(now);
		if(mi[now]>=0)return;
		if(l==r){
				while(1){
						mi[now]+=aft[kiss[l]+1]-kiss[l];
						kiss[l]=aft[kiss[l]+1];
						if(mi[now]>=0)break;
					}
				return;
			}
		int mid=(l+r)>>1;
		ck(now*2,l,mid);
		ck(now*2+1,mid+1,r);
		updata(now);
}
bool lucky(int x){
		if(!x)return 0;
		while(x){
				if(x%10!=4&&x%10!=7)return 0;
				x/=10;
			}
		return 1;
}
int main(){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&a[i]);
		per(i,100000,0)if(lucky(i))aft[i]=i;else aft[i]=aft[i+1];
		build(1,1,n);
		while(m--){
			char opt[7];scanf("%s",opt+1);
			if(opt[1]=='c'){
					int l,r;scanf("%d%d",&l,&r);
					printf("%d\n",count(1,1,n,l,r));
				}
			else
			{
					int l,r,d;scanf("%d%d%d",&l,&r,&d);
					add(1,1,n,l,r,d);
					ck(1,1,n);
				}
			}
		return 0;
}