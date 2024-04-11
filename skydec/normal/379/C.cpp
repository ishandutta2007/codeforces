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
#define MAXN 310000
pii res[MAXN];
int ans[MAXN];
int n;
int main(){
	scanf("%d",&n);rep(i,1,n){res[i].se=i;scanf("%d",&res[i].fi);}
	sort(res+1,res+1+n);ans[res[1].se]=res[1].fi;
	rep(i,2,n)ans[res[i].se]=max(res[i].fi,ans[res[i-1].se]+1);
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}