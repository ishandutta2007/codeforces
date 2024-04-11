#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
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
const int N=110000;
const int inf=1e9;
int s[N],m[N],R[N],need[N],n,q,M,c[N];LL sum_R[N];
inline int find(const int &x){return lower_bound(c+1,c+1+M,x)-c;}
//zhuxi shu
int tot;int root[N];int cl[N*35],cr[N*35];
struct info{
	LL sumR,sumM;
	inline info(LL a=0,LL b=0){sumR=a;sumM=b;}
}mes[N*35];
inline info operator +(const info &a,const info &b){return info(a.sumR+b.sumR,a.sumM+b.sumM);}
inline info operator -(const info &a,const info &b){return info(a.sumR-b.sumR,a.sumM-b.sumM);}
void build(int y,int &x,int l,int r,int v,info pa){
	if(!x)x=++tot;
	if(l==r){mes[x]=mes[y]+pa;return;}
	int mid=(l+r)>>1;
	if(v<=mid){cr[x]=cr[y];build(cl[y],cl[x],l,mid,v,pa);}
	else{cl[x]=cl[y];build(cr[y],cr[x],mid+1,r,v,pa);}
	mes[x]=mes[cl[x]]+mes[cr[x]];
}
info Get(int me,int l,int r,int x,int y){
	if(!me)return info(0,0);if(x<=l&&r<=y)return mes[me];
	info ans=info(0,0);int mid=(l+r)>>1;
	if(x<=mid)ans=ans+Get(cl[me],l,mid,x,y);
	if(y>mid)ans=ans+Get(cr[me],mid+1,r,x,y);
	return ans;
}
inline void build_zxtree(){
	rep(i,1,n){build(root[i-1],root[i],1,M,find(need[i]),info(R[i],m[i]));}
}
inline info zxtree_ask(int l,int r,int T){if(!T)return info(0,0);return Get(root[r],1,M,1,T)-Get(root[l-1],1,M,1,T);}
//----------------
int cov[N*4];LL _ans=0;
inline void down(int me){if(cov[me]>0){cov[me*2]=cov[me*2+1]=cov[me];}}
inline void up(int me){if(cov[me*2]==cov[me*2+1])cov[me]=cov[me*2];else cov[me]=-1;}
inline void work(int me,int l,int r,int T){
	if(cov[me]==0){
		rep(i,l,r){
			if(s[i]+R[i]*1ll*T>m[i])_ans+=m[i]*1ll;
			else _ans+=1ll*s[i]+R[i]*1ll*T;
		}
	}
	else{
		int DT=T-cov[me];
		int up=upper_bound(c+1,c+1+M,DT)-c;
		info ri=zxtree_ask(l,r,up-1);
		_ans+=(sum_R[r]-sum_R[l-1]-ri.sumR)*1ll*DT;
		_ans+=ri.sumM;
	}
	cov[me]=T;
}
void Go(int me,int l,int r,int x,int y,int T){
	if(l^r)down(me);
	if(x<=l&&r<=y&&cov[me]>=0){work(me,l,r,T);return;}
	int mid=(l+r)>>1;
	if(x<=mid)Go(me*2,l,mid,x,y,T);
	if(y>mid)Go(me*2+1,mid+1,r,x,y,T);
	up(me);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d",&s[i],&m[i],&R[i]);
		if(R[i])need[i]=(m[i]+R[i]-1)/R[i];else need[i]=inf+1;
		c[i]=need[i];
		sum_R[i]=sum_R[i-1]+1ll*R[i];
	}
	sort(c+1,c+1+n);M=unique(c+1,c+1+n)-c-1;
	build_zxtree();
	scanf("%d",&q);
	while(q--){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);
		_ans=0;
		Go(1,1,n,l,r,t);
		printf("%I64d\n",_ans);
	}
	return 0;
}