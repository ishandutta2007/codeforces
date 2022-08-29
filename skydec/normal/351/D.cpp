#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#define be(x) (((x)-1)/350)
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
#define MAXN 110000
typedef long long LL;
typedef double db;
struct jdb{
	int l,r,id;
}b[MAXN];int ans[MAXN];int a[MAXN];
inline bool cmp(const jdb &x,const jdb &y){
	if(be(x.l)!=be(y.l))return x.l<y.l;
	if(be(x.l)&1)return x.r<y.r;else return x.r>y.r;
}
int n,m;
int pre[MAXN],next[MAXN],last[MAXN],bj[MAXN];
void init(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);scanf("%d",&m);
	rep(i,1,m){scanf("%d%d",&b[i].l,&b[i].r);b[i].id=i;}
	per(i,n,1){
		pre[i]=last[a[i]];next[last[a[i]]]=i;
		last[a[i]]=i;
		if(pre[i]==0)bj[i]=i;
		else if(pre[pre[i]]==0||(i-pre[i]==pre[i]-pre[pre[i]]))bj[i]=bj[pre[i]];
		else bj[i]=pre[i];
	}
}
int cnt[MAXN];int res=0;int need=0;
int head[MAXN],end[MAXN];int biu[MAXN];
bool watch=0;
inline void add(int x){
	if(!x)return;
	cnt[a[x]]++;if(cnt[a[x]]==1)res++;
	if(!head[a[x]]){
		biu[a[x]]=1;need++;
		head[a[x]]=end[a[x]]=x;
	}
	else
	{
		if(x<head[a[x]]){
			head[a[x]]=x;
			if(biu[a[x]]&&bj[x]<end[a[x]]){biu[a[x]]=0;need--;}
		}
		else
		{
			end[a[x]]=x;
			if(biu[a[x]]&&bj[head[a[x]]]<x){biu[a[x]]=0;need--;}
		}
	}
}
inline void dec(int x){
	if(!x)return;
	cnt[a[x]]--;if(cnt[a[x]]==0)res--;
	if(head[a[x]]==end[a[x]]){
		head[a[x]]=end[a[x]]=0;
		need--;biu[a[x]]=0;
		return;
	}
	if(x==head[a[x]])head[a[x]]=pre[x];else end[a[x]]=next[x];
	if(!biu[a[x]]){
		if(bj[head[a[x]]]>=end[a[x]]){
			biu[a[x]]=1;
			need++;
		}
	}
}
void Task(){
	sort(b+1,b+1+m,cmp);int l,r;l=0;r=0;
	rep(i,1,m){
		while(r<b[i].r)add(++r);
		while(l>b[i].l)add(--l);
		while(r>b[i].r)dec(r--);
		while(l<b[i].l)dec(l++);
		ans[b[i].id]=res+(need==0);
	}
}
void Output(){
	rep(i,1,m)printf("%d\n",ans[i]);
}
int main(){
	init();
	Task();
	Output();
	return 0;
}