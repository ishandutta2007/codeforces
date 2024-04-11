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
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 10005
map<int,int>ls;
int a[MAXN];int n;
int pl,pr,vl,vr,k;
int low,up;
void dfs(int x){
	if(ls[x])return;
	ls[x]=1;
	if(x&&x>=low&&x<=up)a[++n]=x;
	LL res=x*10ll+4ll;
	if(res<=up)dfs(res);
	res=x*10ll+7ll;
	if(res<=up)dfs(res);
}
db gl(int l,int r,int x,int y){
	int u=min(r,y)-max(l,x)+1;
	if(u<=0)return 0.0;
	return (u*1.)/(r-l+1.);
}
int main(){
	scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
	low=min(pl,vl);up=max(pr,vr);
	dfs(0);
	sort(a+1,a+1+n);
	db res=0;a[0]=-1;a[n+1]=1000000007;
	rep(i,k,n){
		res+=gl(pl,pr,a[i],a[i+1]-1)*gl(vl,vr,a[i-k]+1,a[i-k+1]);
		res+=gl(vl,vr,a[i],a[i+1]-1)*gl(pl,pr,a[i-k]+1,a[i-k+1]);
	}
	if(k==1)rep(i,1,n)res-=gl(pl,pr,a[i],a[i])*gl(vl,vr,a[i],a[i]);
	printf("%.10lf\n",res);
	return 0;
}