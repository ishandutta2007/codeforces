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
#define jsb 1000000007
int f[2005][2005];
int g[2005][2005];
char a[2005];
int n,k;
inline void A(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);f[0][0]=1;g[0][0]=1;
	rep(i,1,n)rep(j,0,k){
		A(f[i][j],g[i-1][j]*1ll*(a[i]-'a')%jsb);
		per(p,i,1){
			if((n-i+1)*(i-p+1)>j)break;
			A(f[i][j],f[p-1][j-(n-i+1)*(i-p+1)]*1ll*('z'-a[i])%jsb);
		}
		A(g[i][j],g[i-1][j]);
		A(g[i][j],f[i][j]);
	}
	printf("%d\n",g[n][k]);
	return 0;
}