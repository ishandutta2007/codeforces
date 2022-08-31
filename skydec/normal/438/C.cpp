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
const int jsb=1000000007;
const int N=205;
inline LL cha(int x1,int y1,int x2,int y2){return x1*1ll*y2-x2*1ll*y1;}
int f[N][N];bool vis[N][N];
int n;int x[N],y[N];
int dp(int l,int r){
	if(vis[l][r])return f[l][r];
	if(l==r-1)return 1;
	vis[l][r]=1;
	rep(k,l+1,r-1)if(cha(x[k]-x[l],y[k]-y[l],x[r]-x[l],y[r]-y[l])>0)f[l][r]=(f[l][r]+dp(l,k)*1ll*dp(k,r))%jsb;
	return f[l][r];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1];y[n+1]=y[1];
	LL area=0;
	rep(i,1,n)area+=cha(x[i],y[i],x[i+1],y[i+1]);
	if(area<0){
		rep(i,1,n/2){
			swap(x[i],x[n+1-i]);
			swap(y[i],y[n+1-i]);
		}
		x[n+1]=x[1];y[n+1]=y[1];
	}
	printf("%d\n",dp(1,n));
	return 0;
}