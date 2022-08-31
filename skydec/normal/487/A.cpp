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
int f[3][4];
int main(){
	int h,a,d;
	int ans=1e9;
	rep(i,1,2)rep(j,1,3)scanf("%d",&f[i][j]);
	scanf("%d%d%d",&h,&a,&d);
	rep(i,f[1][2],200)rep(j,f[1][3],100){
		int k2=(i-f[1][2])*a+(j-f[1][3])*d;
		int x=max(i-f[2][3],0);int y=max(f[2][2]-j,0);
		if(x==0)continue;
		k2+=max(((f[2][1]+x-1)/x)*y+1-f[1][1],0)*h;
		if(k2<ans)ans=k2;
	}
	printf("%d\n",ans);
	return 0;
}
//