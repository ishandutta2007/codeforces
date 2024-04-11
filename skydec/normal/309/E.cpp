#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int MAXN=2005;
struct fat{int l,r,id;}a[MAXN];
inline bool cmp(const fat &a,const fat &b){return a.l<b.l;}
int n;int v[MAXN];int last[MAXN],sum[MAXN];bool use[MAXN];
inline bool jiao(const int &x,const int &y){
	return max(a[x].l,a[y].l)<=min(a[x].r,a[y].r);
}
inline bool check(int dis){
	rep(i,1,n)last[i]=n;
	int now=1;
	memset(use,0,sizeof use);
	rep(i,1,n)if(a[i].r<a[now].r)now=i;
	rep(i,1,n){
		v[i]=now;last[now]=i;use[now]=1;
		rep(j,1,n)if(jiao(now,j))last[j]=min(last[j],last[now]+dis);
		memset(sum,0,sizeof sum);
		rep(j,1,n)sum[last[j]]++;
		rep(j,1,n)sum[j]+=sum[j-1];
		rep(j,1,n)if(sum[j]>j)return 0;
		int first=0;
		rep(j,i+1,n)if(sum[j]==j){
			first=j;
			break;
		}
		now=0;
		rep(j,1,n)if(!use[j]&&last[j]<=first)
		if(a[j].r<a[now].r||!now){
			now=j;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d%d",&a[i].l,&a[i].r);a[i].id=i;}
	sort(a+1,a+1+n,cmp);
	int l,r,rp;l=0;r=n;rp=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid,rp=mid;
		else l=mid+1;
	}
	if(check(l))rp=l;
	check(rp);
	rep(i,1,n)printf("%d ",a[v[i]].id);
	return 0;
}