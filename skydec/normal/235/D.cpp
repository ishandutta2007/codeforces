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
const int MAXN=3005;
vector<int>p[MAXN];
int n;db ans=0;
bool instack[MAXN];int rd[MAXN];int circle;int q[MAXN];
inline void TopSort(){
	rep(i,0,n-1)if(rd[i]==1)q[++q[0]]=i;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1)if((--rd[p[x][j]])==1)q[++q[0]]=p[x][j];
	}
	circle=n-q[0];
}
int d1[MAXN],d2[MAXN];
void dfs(int x,int d){
	if(!d1[x])d1[x]=d;
	else d2[x]=d;
	instack[x]=1;
	rep(i,0,p[x].size()-1)if(!instack[p[x][i]])dfs(p[x][i],d+1);
	instack[x]=0;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int a,b;scanf("%d%d",&a,&b);
		p[a].pb(b);p[b].pb(a);
		rd[a]++;rd[b]++;
	}
	TopSort();
	rep(i,0,n-1){
		memset(d1,0,sizeof d1);
		memset(d2,0,sizeof d2);
		dfs(i,1);
		rep(j,0,n-1)if(!d2[j])ans+=1./d1[j];
		else ans+=(1./d1[j])+(1./d2[j])-(1./((d1[j]+d2[j]+circle-2)/2));
	}
	printf("%.10lf\n",ans);
	return 0;
}