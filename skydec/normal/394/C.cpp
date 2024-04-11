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
#define MAXN 1005
int f[MAXN][MAXN];
int n,m;
int all,air,one;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){
		int v;scanf("%d",&v);
		if(v==11)all++;
		else if(v==10)one++;
		else if(v==1)one++;
		else air++;
	}
	rep(i,1,n)rep(j,1,m)if(all){
		f[i][j]=11;all--;
	}
	rep(i,1,n)rep(j,1,m)if(!f[i][j])if(one){
		one--;f[i][j]=10;
		if(one&&i<n){one--;f[i+1][j]=1;}
	}
	rep(i,1,n){
		rep(j,1,m)printf("%d%d ",f[i][j]/10,f[i][j]%10);
		printf("\n");
	}
	return 0;
}