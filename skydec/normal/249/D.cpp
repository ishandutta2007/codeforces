#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define eps (1e-8)
#define pii pair<LL,LL>
using namespace std;
#define MAXN 210000
typedef long long LL;
typedef double db;
bool cant[MAXN];
LL sina1,cosa1,sina2,cosa2;
int n;struct E{db x,y;}e[MAXN];
inline bool cmp(const E &a,const E &b){return a.x>b.x;}
map<db,int>ls;int tot=0;db tmp[MAXN];db ddd[MAXN];
void LS(){
	rep(i,1,n)tmp[i]=e[i].y;
	sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++)if(i==1||tmp[i]>tmp[i-1]+eps){ls[tmp[i]]=++tot;ddd[tot]=tmp[i];}
	rep(i,1,n){e[i].y=ls[e[i].y];}
}
int cnt[MAXN];
int ask(int x){
	int res=0;if(x<0)return -1;
	for(;x;x-=lowbit(x))res=max(res,cnt[x]);
	return res;
}
void add(int x,int v){
	if(!x)return;
	for(;x<=n;x+=lowbit(x))cnt[x]=max(v,cnt[x]);
}
int f[MAXN];
int main(){
	scanf("%d",&n);scanf("%I64d/%I64d",&sina1,&cosa1);scanf("%I64d/%I64d",&sina2,&cosa2);
	rep(i,1,n){
		LL x,y;scanf("%I64d%I64d",&x,&y);
		e[i].x=y-x*(sina1*1./cosa1);
		if(cosa2==0)e[i].y=-x;
		else e[i].y=y-x*(sina2*1./cosa2);
	}
	n++;e[n].x=e[n].y=0;
	LS();
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++){
		int j=i;while(j<n&&fabs(e[j+1].x-e[i].x)<eps)j++;
		rep(k,i,j)f[k]=ask((int)(e[k].y+eps-1))+1;
		rep(k,i,j)add((int)(e[k].y+eps),f[k]);
		i=j;
	}
	int res=0;
	rep(i,1,n)if(e[i].x==0&&ddd[(int)(e[i].y+eps)]==0)res=f[i]-1;
	printf("%d\n",res);
	return 0;
}