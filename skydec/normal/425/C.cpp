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
typedef set<int>::iterator it;
const int N=110000;
set<int>pos[N];
int n,m,s,e;int a[N],b[N];int ans=0;
int f[333];
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&e);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){
		scanf("%d",&b[i]);
		pos[b[i]].insert(i);
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	rep(i,0,n-1)per(j,s/e,0){
		it bg=pos[a[i+1]].upper_bound(f[j]);
		if(bg==pos[a[i+1]].end())continue;
		f[j+1]=min(f[j+1],*bg);
		if(i+1+f[j+1]+(j+1)*e<=s)ans=max(ans,j+1);
	}
	printf("%d\n",ans);
	return 0;
}