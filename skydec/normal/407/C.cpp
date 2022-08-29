#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define se second
#define fi first
#define VI vector<int>
#define rep(i,j,k) for(int i=j;i<=(int)k;i++)
#define per(i,j,k) for(int i=j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int n,m;const int jsb=1000000007;
int f[110000][113],c[110000][113];int a[110000];
inline void add(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;if(x<0)x+=jsb;
}
int main(){
	scanf("%d%d",&n,&m);
	c[0][0]=1;
	rep(i,1,100105){
		c[i][0]=1;
		for(int j=1;j<=105&&j<=i;j++){
			add(c[i][j],c[i-1][j]);
			add(c[i][j],c[i-1][j-1]);
		}
	}
	rep(i,1,n)scanf("%d",&a[i]);
	while(m--){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		rep(i,0,k)add(f[l][i],c[k][k-i]),add(f[r+1][i],-c[r-l+k+1][k-i]);
	}
	rep(i,1,n)per(j,101,1){
		add(f[i+1][j-1],f[i][j]);
		add(f[i+1][j-1],f[i][j-1]);
	}
	rep(i,1,n)add(a[i],f[i][0]);
	rep(i,1,n)printf("%d ",(a[i]+jsb)%jsb);
	return 0;
}