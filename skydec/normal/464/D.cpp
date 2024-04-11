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
db f[605],g[605];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	int m=600;if(m>n)m=n;
	rep(i,1,n){
		rep(j,1,m){
			g[j]=((k-1)*1./k)*f[j];
			db res=j*1.*f[j];
			res+=j*1.*(j+3)/2;
			res+=f[j+1];
			g[j]+=res/(k*1.*(j+1));
		}
		rep(j,1,m)f[j]=g[j],g[j]=0;
	}
	printf("%.10lf\n",k*1.*f[1]);
	return 0;
}