#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int N=10005;
const LL inf=(LL)(1e18);
LL f[2][N];
int n,c;
int p[N],s[N];
int main(){
	scanf("%d%d",&n,&c);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)scanf("%d",&s[i]);
	rep(i,0,n)f[0][i]=inf;
	f[0][0]=0;
	int now=0;
	rep(i,1,n){
		rep(j,0,n)f[now^1][j]=inf;
		rep(j,0,i-1){
			f[now^1][j]=min(f[now^1][j],f[now][j]+p[i]+j*1ll*c);
			f[now^1][j+1]=min(f[now^1][j+1],f[now][j]+s[i]);
		}
		now^=1;
	}
	LL ans=inf;
	rep(i,0,n){
		ans=min(f[now][i],ans);
	}
	printf("%I64d\n",ans);
	return 0;
}