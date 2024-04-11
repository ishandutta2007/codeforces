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
using namespace std;
#define MAXN 5005
int f[MAXN][MAXN];
int n,m;
inline void Min(int &x,int y){if(y<x)x=y;}
int main(){
	scanf("%d%d",&n,&m);memset(f,63,sizeof f);
	f[0][0]=0;
	for(int i=0;i<n;i++){
		int a;db b;scanf("%d%lf",&a,&b);
		for(int j=0;j<=m;j++)
		if(a>j){
			Min(f[i+1][a],f[i][j]);
			Min(f[i+1][j],f[i][j]+1);
		}
		else if(a==j)Min(f[i+1][j],f[i][j]);
		else Min(f[i+1][j],f[i][j]+1);
	}
	int res=f[0][1];
	for(int i=0;i<=m;i++)Min(res,f[n][i]);
	printf("%d\n",res);
	return 0;
}