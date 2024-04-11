#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
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
const int N=405;
int a[N][N];int c[N][160005];int n,m;
int f[N][N];int ans;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,n){
		rep(len,1,m)rep(l,1,m-len+1){
			int r=l+len-1;
			if(l==r)f[l][r]=max(f[l][r],c[l][a[i][l]]);
			else{
				f[l][r]=max(f[l][r],max(f[l+1][r],f[l][r-1]));
				f[l][r]=max(f[l][r],max(c[l][a[i][r]],c[r][a[i][l]]));
				if(a[i][l]==a[i][r])f[l][r]=i;
			}
			ans=max(ans,(i-f[l][r])*(r-l+1));
		}
		rep(j,1,m)c[j][a[i][j]]=i;
	}
	printf("%d\n",ans);
	return 0;
}