#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
int n,k,d;int a[N],b[N];
struct link{int l,r,w;}sma[N],big[N];
int ts,tb;map<int,int>gt;
int lazy[N*4];int mi[N*4];
void build(int me,int l,int r){
	if(l==r){
		mi[me]=-l;
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid);
	build(me*2+1,mid+1,r);
	mi[me]=min(mi[me*2],mi[me*2+1]);
}
void down(int me){
	if(lazy[me]==0)return;
	rep(i,0,1){
		lazy[me*2+i]+=lazy[me];
		mi[me*2+i]+=lazy[me];
	}
	lazy[me]=0;
}
void add(int me,int l,int r,int x,int y,int v){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		lazy[me]+=v;mi[me]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	mi[me]=min(mi[me*2],mi[me*2+1]);
}
int work(int me,int l,int r,int x,int y,int key){
	if(l^r)down(me);if(mi[me]>key)return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	int u1=-1;
	if(y>mid)u1=work(me*2+1,mid+1,r,x,y,key);
	if(x<=mid&&u1==-1)u1=work(me*2,l,mid,x,y,key);
	return u1;
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	rep(i,1,n)scanf("%d",&a[i]);
	if(!d){
		int ans=0;int L,R;
		rep(i,1,n){
			int j=i;while(j<n&&a[j+1]==a[i])j++;
			if(j-i+1>ans){L=i;R=j;ans=j-i+1;}
			i=j;
		}
		printf("%d %d\n",L,R);
		return 0;
	}
	rep(i,1,n)b[i]=((a[i]%d)+d)%d;
	build(1,1,n);int ans=0;
	rep(i,1,n)a[i]=(a[i]-b[i])/d;
	int Ri=n;int L,R;
	per(i,n,1){
		if((i^n)&&b[i]!=b[i+1])Ri=i;
		if(gt.find(a[i])!=gt.end())Ri=min(Ri,gt[a[i]]-1);
		gt[a[i]]=i;
		while(ts&&sma[ts].w>=a[i]){add(1,1,n,sma[ts].l,sma[ts].r,sma[ts].w);ts--;}
		link now;now.l=i;if(!ts)now.r=n;else now.r=sma[ts].l-1;now.w=a[i];
		sma[++ts]=now;add(1,1,n,now.l,now.r,-now.w);
		
		while(tb&&big[tb].w<=a[i]){add(1,1,n,big[tb].l,big[tb].r,-big[tb].w);tb--;}
		now.l=i;if(!tb)now.r=n;else now.r=big[tb].l-1;now.w=a[i];
		big[++tb]=now;add(1,1,n,now.l,now.r,now.w);
		
		int id=work(1,1,n,i,Ri,k-i);
		if(id==-1)continue;
		if(id-i+1>=ans){ans=id-i+1;L=i;R=id;}
	}
	printf("%d %d\n",L,R);
	return 0;
}