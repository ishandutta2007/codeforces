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
int a[44][44];int n;int b[44];
int main(){
	scanf("%d",&n);int x=(n+1)/2;
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	int res=-1e9;
	rep(i,0,(1<<x)-1){
		rep(j,1,x){b[j]=(i>>(j-1))&1;if(b[j]==0)b[j]=-1;}
		int tmp=0;
		rep(j,1,x-1){
			int v=-1e9;
			for(int k=-1;k<=1;k+=2){
				int u=k*a[x][j]+k*b[x]*a[x][j+x];
				rep(l,1,x-1)u+=max(a[l][j]+k*a[l+x][j]+b[l]*a[l][j+x]+k*b[x]*b[l]*a[l+x][j+x],-a[l][j]+(-k)*a[l+x][j]+(-b[l])*a[l][j+x]+(-k)*b[l]*b[x]*a[l+x][j+x]);
			  if(u>v)v=u;
			}
			tmp+=v;
		}
		rep(j,1,x-1)tmp+=b[j]*a[j][x]+b[j]*b[x]*a[j+x][x];
		tmp+=b[x]*a[x][x];
		res=max(res,tmp);
	}
	printf("%d\n",res);
	return 0;
}