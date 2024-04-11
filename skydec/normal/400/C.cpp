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
int x,y,z;
int n,m,p;
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	x%=4;y%=2;z%=4;
	while(p--){
		int sx,sy;scanf("%d%d",&sx,&sy);
		int N=n;int M=m;
		rep(i,1,x){
			int tmp=sy;
			sy=N-sx+1;
			sx=tmp;
			swap(N,M);
		}
		rep(i,1,y)sy=M-sy+1;
		rep(i,1,z){
			int tmp=sy;
			sy=sx;
			sx=M-tmp+1;
			swap(N,M);
		}
		printf("%d %d\n",sx,sy);
	}
	return 0;
}