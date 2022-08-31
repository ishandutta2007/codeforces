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
int head[MAXN],next[MAXN],p[MAXN],w[MAXN];int tot=0;LL ans=0;int color[MAXN];int ck=0;int cnt[MAXN];int n;
inline void L(int a,int b,int v){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;w[tot]=v;}
bool xy(int x){while(x){if(x%10!=4&&x%10!=7)return 0;x/=10;}return 1;}
void dfs(int x,int c){
	if(color[x])return;color[x]=c;for(int u=head[x];u;u=next[u])if(!xy(w[u]))dfs(p[u],c);
}
int main(){
	scanf("%d",&n);rep(i,1,n-1){int a,b,v;scanf("%d%d%d",&a,&b,&v);L(a,b,v);L(b,a,v);}
	rep(i,1,n)if(!color[i])dfs(i,++ck);rep(i,1,n)cnt[color[i]]++;
	rep(i,1,n)ans+=(n-1-cnt[color[i]])*1ll*(n-cnt[color[i]]);printf("%I64d\n",ans);return 0;
}