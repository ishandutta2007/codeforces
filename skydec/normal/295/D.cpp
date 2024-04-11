#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#define pb push_back
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define jsb 1000000007
int n,m;
int f[2005][2005],g[2005][2005];
inline void ADD(int &x,int y){
	x+=y;x%=jsb;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		int sum=0;
		rep(j,2,m){
			ADD(f[i][j],g[i-1][j]+1);
			ADD(sum,f[i][j]);
			ADD(g[i][j],(sum+g[i][j-1])%jsb);
		}
	}
	int ans=0;
	rep(i,1,n)rep(j,1,m)ADD(ans,f[i][j]*1ll*(g[n-i][j]-f[n-i][j]+1)%jsb*1ll*(m-j+1)%jsb);
	printf("%d\n",(ans+jsb)%jsb);
	return 0;
}