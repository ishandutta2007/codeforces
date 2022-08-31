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
int f[1005][1005];
int n;
int main(){
	scanf("%d",&n);
	if(n==4){
		printf("-1");
		return 0;
	}
	rep(i,1,n)f[i][i%n+1]=1;
	rep(i,1,n)rep(j,i+2,n)if(i!=1||j!=n){
		if((j-i)&1)f[j][i]=1;else f[i][j]=1;
	}
	rep(i,1,n){rep(j,1,n)printf("%d ",f[i][j]);printf("\n");}
	return 0;
}