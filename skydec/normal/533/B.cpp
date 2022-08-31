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
const int N=210000;
vector<int>son[N];
int val[N];
LL f[2][2][N];
int n;
void dfs(int x){
	LL bag[2];
	bag[0]=0;bag[1]=-((LL)1e16);
	for(int i=0;i<(int)son[x].size();i++){
		dfs(son[x][i]);int y=son[x][i];
		LL tmp1=max(bag[1]+max(f[1][1][y],f[0][0][y]),bag[0]+max(f[1][0][y],f[0][1][y]));
		LL tmp0=max(bag[1]+max(f[1][0][y],f[0][1][y]),bag[0]+max(f[1][1][y],f[0][0][y]));
		bag[0]=max(bag[0],tmp0);
		bag[1]=max(bag[1],tmp1);
	}
	
	f[1][0][x]=val[x]+bag[0];
	f[0][0][x]=bag[0];
	f[0][1][x]=bag[1];
	
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int p;scanf("%d%d",&p,&val[i]);
		if(p==-1)continue;
		son[p].pb(i);
	}
	dfs(1);
	printf("%I64d\n",max(f[1][0][1],max(f[0][0][1],f[0][1][1])));
	return 0;
}