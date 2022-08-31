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
#define MAXN 1010000
int n;int f[MAXN];
const int jsb=1000000007;
int main(){
	scanf("%d",&n);
	int a[3];a[1]=a[2]=0;
	rep(i,1,n){
		int v;scanf("%d",&v);a[v]++;
	}
	f[0]=f[1]=1;
	rep(i,2,a[1])f[i]=(f[i-2]*1ll*(i-1)+f[i-1])%jsb;
	int ans=f[a[1]];
	rep(i,a[1]+1,n)ans=ans*1ll*i%jsb;
	printf("%d\n",ans);
	return 0;
}