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
#define MAXN 200
db w[MAXN][MAXN];db a[MAXN][MAXN],b[MAXN][MAXN];
int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%lf",&w[i][j]);
	rep(i,1,n)rep(j,1,n){
		a[i][j]=(w[i][j]+w[j][i])/2.;
		b[i][j]=(w[i][j]-w[j][i])/2.;
	}
	rep(i,1,n){rep(j,1,n)printf("%.5lf ",a[i][j]);printf("\n");}
	rep(i,1,n){rep(j,1,n)printf("%.5lf ",b[i][j]);printf("\n");}
	return 0;
}