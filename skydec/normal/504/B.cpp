//orz YJN
//
//
//
//IGM
//
//
//
//
//
//Orz Orz Orz Orz Orz
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
const int MAXN=310000;
int a[MAXN],b[MAXN],n;
int c[MAXN],d[MAXN];
int cnt[MAXN];
inline void add(int x,int v){
	for(;x<=n;x+=x&-x)cnt[x]+=v;
}
inline int GetRank(int x){
	int res=x-1;
	for(x--;x;x-=x&-x)res-=cnt[x];
	return res;
}
inline void del(int x){
	for(;x<=n;x+=x&-x)cnt[x]--;
}
inline int GetAAA(int x){
	int rp=0;x++;
	for(int i=17;i>=0;i--)if((x>=cnt[rp+(1<<i)])&&((rp+(1<<i))<=n)){
		x-=cnt[rp+(1<<i)];
		rp+=(1<<i);
	}
	return rp;
}
inline void Get(int *A,int *B,int n){
	memset(cnt,0,sizeof cnt);
	rep(i,1,n-1){
		B[n-i]=GetRank(A[i]);
		add(A[i],1);
	}
}
inline void ReGet(int *A,int n){
	memset(cnt,0,sizeof cnt);
	rep(i,1,(1<<18))add(i,1);
	per(i,n-1,0){
		int u=GetAAA(A[i]-1);
		printf("%d ",u);
		del(u+1);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,n){a[i]++;b[i]++;}
	Get(a,c,n);
	Get(b,d,n);
	rep(i,1,n-1)c[i]+=d[i];
	rep(i,1,n-1){
		c[i+1]+=c[i]/(i+1);
		c[i]%=(i+1);
	}
	ReGet(c,n);
	return 0;
}