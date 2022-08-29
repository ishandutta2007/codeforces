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
inline pii huan(const int &a,const int &b,const int &c,const int &d){
	pii res;
	if(c<=a&&a<=d){
		res.fi=d-(a-c);
	}
	else res.fi=a;
	
	if(c<=b&&b<=d){
		res.se=d-(b-c);
	}
	else res.se=b;
	
	return res;
}
db f[105][105];db g[105][105];
int n,tt;int a[105];
int main(){
	scanf("%d%d",&n,&tt);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)rep(j,i+1,n)if(a[i]>a[j])f[i][j]=1;else f[j][i]=1;
	
	while(tt--){
		rep(l,1,n)rep(r,l,n)rep(i,1,n)rep(j,1,n){
			pii gt=huan(i,j,l,r);
			g[gt.fi][gt.se]+=f[i][j]*1./((n+1)*n/2.);
		}
		
		rep(i,1,n)rep(j,1,n){
			f[i][j]=g[i][j];
			g[i][j]=0;
		}
	}
	db res=0;
	rep(i,1,n)rep(j,i+1,n)res+=f[i][j];
	printf("%.10lf\n",res);
	return 0;
}