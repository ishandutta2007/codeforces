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
#define MAXN 110000
pii e[MAXN];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&e[i].fi,&e[i].se);
	sort(e+1,e+1+n);
	for(int i=1;i<n;i++){
		int u=e[i].se;int f=0;
		for(int j=e[i].fi+1;j<=e[i+1].fi;j++)
		{
			if(u%4!=0)f=1;
			u/=4;
			if(!u)break;
		}
		e[i+1].se=max(u+f,e[i+1].se);
	}
	int juji=e[n].fi;
	int u=e[n].fi;int res=e[n].se;
	while(res!=1){
		u++;
		res=(res/4)+(res%4!=0);
	}
	if(u==juji)u++;
	printf("%d\n",u);
	return 0;
}