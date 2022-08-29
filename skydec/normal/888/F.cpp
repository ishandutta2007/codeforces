#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=505;
int a[N][N];
int n;
int f[N][N][2][2];
int dp(int l,int r,int cl,int cr){
	if(l>r)return 1;
	if(f[l][r][cl][cr]!=-1)return f[l][r][cl][cr];
	int ans=0;
	int r1=r%n+1;
	int l1=(l+n-2)%n+1;
	//link to r1
	if(cr)rep(i,l,r)if(a[i][r1]){
		ans=(ans+dp(l,i-1,0,1)*1ll*dp(i+1,r,1,1))%P;
	}
	if(cl)rep(i,l,r)if(a[l1][i]){
		ans=(ans+dp(l,i-1,1,cr)*1ll*dp(i+1,r,1,cr))%P;
	}
	return f[l][r][cl][cr]=ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	memset(f,-1,sizeof f);
	int ans=0;
	rep(i,2,n)if(a[1][i]){
		ans=(ans+dp(2,i-1,0,1)*1ll*dp(i+1,n,1,1))%P;
	}
	printf("%d\n",ans);
	return 0;
}